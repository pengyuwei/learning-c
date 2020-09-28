#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h> // for close
#include <arpa/inet.h>
#include <sys/epoll.h>

#define MAXSIZE     1024
#define LISTENQ     5
#define FDSIZE      1000
#define EPOLLEVENTS 100

static void do_accpet(int epoll_fd, int listen_fd);
static void do_read(int epoll_fd, int fd, char *buf);
static void do_write(int epoll_fd, int fd, char *buf);
static void delete_event(int epoll_fd, int fd, int state);
static void modify_event(int epoll_fd, int fd, int state);
static void add_event(int epoll_fd, int fd, int state);

static void add_event(int epoll_fd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ev);
}

static void do_accpet(int epoll_fd, int listen_fd)
{
    struct sockaddr client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    memset(&client_addr, 0, sizeof(client_addr));

    int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd == -1) {
        perror("error @accept");
    }
    
    add_event(epoll_fd, client_fd, EPOLLIN);
}

// 读处理
static void do_read(int epoll_fd, int fd, char *buf)
{
    int ret = 0;
    ret = read(fd, buf, MAXSIZE);
    if (ret == -1) {
        perror("read error");
        close(fd);
        delete_event(epoll_fd, fd, EPOLLIN);
    } else if (ret == 0) {
        fprintf(stderr, "client close.\n");
        close(fd);
        delete_event(epoll_fd, fd, EPOLLIN);
    } else {
        printf("in: %s\n", buf);
        modify_event(epoll_fd, fd, EPOLLOUT);
    } 
}

// 写处理
static void do_write(int epoll_fd, int fd, char *buf)
{
    int ret = 0;
    ret = write(fd, buf, strlen(buf));
    if (ret == -1) {
        perror("write error:");
        close(fd);
        delete_event(epoll_fd, fd, EPOLLOUT);
    } else {
        printf("out: %s\n", buf);
        modify_event(epoll_fd, fd, EPOLLIN);
    }
    memset(buf, 0, MAXSIZE); 
}

static void delete_event(int epoll_fd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, &ev);
}

static void modify_event(int epoll_fd, int fd, int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &ev);
}

static void handle_events(int epoll_fd, struct epoll_event *events, int num, int listen_fd, char *buf)
{
     int i;
     int fd;

     for (i = 0;i < num;i++)
     {
        fd = events[i].data.fd;
        if ((fd == listen_fd) &&(events[i].events & EPOLLIN)) {
            do_accpet(epoll_fd, listen_fd);
            printf("accept\n");
        } else if (events[i].events & EPOLLIN) {
            do_read(epoll_fd, fd, buf);
        } else if (events[i].events & EPOLLOUT) {   
            strcpy(buf, "Hello\n");
            do_write(epoll_fd, fd, buf);
        }
     }
}

int main(int argc, char *argv[])
{
    int ret = 0;
    struct epoll_event events[EPOLLEVENTS] = {0};
    struct sockaddr_in server_addr;
    int qlen = 0;
    char buf[1024] = {0};
    int listen_fd = 0;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12020);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    listen_fd = socket(server_addr.sin_family, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("server: socket");
        return -1;
    }
    if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))) {
        perror("server: bind");
        close(listen_fd);
        return -1;
    }
    if (listen(listen_fd, qlen) < 0) {
        perror("server: listen");
        close(listen_fd);
        return -1;
    }
    printf("Listening...\n");

    // 1. 创建文件描述符
    int epoll_fd = epoll_create(FDSIZE);

    // 2. 添加监听事件
    add_event(epoll_fd, listen_fd, EPOLLIN);

    while (1) {
        // 3. 等待已经准备好的描述符事件
        ret = epoll_wait(epoll_fd, events, EPOLLEVENTS, -1);
        // 4. 处理事件
        handle_events(epoll_fd, events, ret, listen_fd, buf);
    }

    return ret;
}