#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h> // for close
#include <arpa/inet.h>

int conn(struct sockaddr * addr, socklen_t alen)
{
    int type = SOCK_STREAM, protocol = 0;
    int fd = 0;
    int ret = 0;
    char buf[256] = {0};

    /*
    Client step:
    1. socket
    2. connect
    3. recv
    4. close
    */

    fd = socket(addr->sa_family, type, protocol);
    if (fd < 0) {
        perror("socket");
        return -1;
    }
    if (connect(fd, addr, alen) == -1) {
        perror("connect");
        return fd;
    }

    if ((ret = recv(fd, buf, sizeof(buf) - 1, 0)) == -1) {
        perror("recv");
        exit(1);
    }
    printf("client: received '%s'\n",buf);

    close(fd);

    return 0;
}

int main()
{
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12020);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    struct sockaddr *paddr = (struct sockaddr *)&server_addr;

    conn(paddr, sizeof(server_addr));
    return 0;
}