#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8888

int main() {
    int server_fd, socket_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *msg = "HTTP/1.1 200 OK\r\n"
        "Connection: keep-alive\r\n"
        "Content-Type: text/html\r\n"
        "Date: Tue, 18 Apr 2023 08:32:21 GMT\r\n"
        "Server: bfe/1.0.8.18\r\n"
        "\r\n"
        "<!DOCTYPE html>\r\n"
        "<!--STATUS OK--><html>\r\n<head><meta http-equiv=content-type content=text/html;charset=utf-8><title>io</title></head>\n<body>Hello</body></html>\r\n";

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
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a connection at %d...\n", PORT);

    while (1) {
        if ((socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }

        read(socket_fd, buffer, 1024);

        send(socket_fd, msg, strlen(msg), 0);

        close(socket_fd);
        socket_fd = 0;
    }

    close(server_fd);
    server_fd = 0;

    return 0;
}