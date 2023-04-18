#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

/*
GET / HTTP/1.1
Host: www.io.com
User-Agent: curl/7.58.0
Accept: *

HTTP/1.1 200 OK
Connection: keep-alive
Content-Type: text/html
Date: Tue, 18 Apr 2023 08:32:21 GMT
Server: bfe/1.0.8.18

<!DOCTYPE html>
<!--STATUS OK--><html> <head><meta http-equiv=content-type content=text/html;charset=utf-8><title>io</title></head> <body>Hello</body></html>
*/

void child_process(int socket_fd) {
    char buffer[1024] = {0};
    const char *msg = "HTTP/1.1 200 OK\r\n"
        "Connection: keep-alive\r\n"
        "Content-Type: text/html\r\n"
        "Date: Tue, 18 Apr 2023 08:32:21 GMT\r\n"
        "Server: bfe/1.0.8.18\r\n"
        "\r\n"
        "<!DOCTYPE html>\r\n"
        "<!--STATUS OK--><html>\r\n<head><meta http-equiv=content-type content=text/html;charset=utf-8><title>io</title></head>\n<body>Hello</body></html>\r\n";
    // printf("Connection established.\n");

    read(socket_fd, buffer, 1024);
    // int len = read(socket_fd, buffer, 1024);
    // printf("Received %d bytes: \n%s\n", len, buffer);

    send(socket_fd, msg, strlen(msg), 0);
    // printf("send %ld bytes:\n%s\n", strlen(msg), msg);

    close(socket_fd);
    socket_fd = 0;
    exit(0);
}

int main(int argc, char *argv[]) {
    int port = 80;
    int server_fd, socket_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pid_t pid;

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

    printf("Waiting for a connection at %d...\n", port);

    while (1) {
        if ((socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }

        pid = fork();
        if (pid < 0) {
            perror("fork error\n");
        } else if (pid == 0) {
            // child
            close(server_fd);
            server_fd = 0;

            child_process(socket_fd);
            exit(0);
        } else {
            // parent
            close(socket_fd);
            socket_fd = 0;
        }
    }

    return 0;
}