#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10000
int running = 1;
int num_quited_threads = 0;

void *child_thread(void *arg) {
    char buffer[1024] = {0};
    const char *msg = "HTTP/1.1 200 OK\r\n"
        "Connection: keep-alive\r\n"
        "Content-Type: text/html\r\n"
        "Date: Tue, 18 Apr 2023 08:32:21 GMT\r\n"
        "Server: bfe/1.0.8.18\r\n"
        "\r\n"
        "<!DOCTYPE html>\r\n"
        "<!--STATUS OK--><html>\r\n<head><meta http-equiv=content-type content=text/html;charset=utf-8><title>io</title></head>\n<body>Hello</body></html>\r\n";

    int socket_fd = *(int *)arg;
    read(socket_fd, buffer, 1024);
    // printf("read %d bytes: %s", len, buffer);
    // nc 127.0.0.1 8888
    // quit
    if (strcmp(buffer, "quit\n") == 0) {
        running = 0;
    }
    send(socket_fd, msg, strlen(msg), 0);

    close(socket_fd);
    socket_fd = 0;
    num_quited_threads++;
    pthread_exit((void *)NULL);
    return NULL;
}

int main(int argc, char *argv[]) {
    int port = 80;
    int server_fd, socket_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t thread_id[MAX_CLIENTS];
    int status, num_threads = 0;

    if (argc < 2) {
        printf("Usage: ./server-2.out <listen port>\n");
        return 0;
    }
    port = atoi(argv[1]);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed.");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    printf("Listening %d...\n", port);

    while (running) {
        if ((socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }
        pthread_create(&thread_id[num_threads++], NULL, child_thread, (void *)&socket_fd);
        printf("threads count=%d, quited_threads=%d\n", num_threads, num_quited_threads);
    }

    for (int i = 0; i < num_threads; i++) {
        printf("waiting %d\r", i);
        pthread_join(thread_id[i], (void **)&status);
    }
    printf("\nTotal %d threads\n", num_threads);

    return 0;
}