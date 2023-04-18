#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>

int time_diff(struct timeval *start, struct timeval *end) {
    int diff;
    diff = (end->tv_sec - start->tv_sec) * 1000000 + (end->tv_usec - start->tv_usec);
    return diff;
}

int main(int argc, char *argv[]) {
    int client_fd;
    struct hostent *server;
    struct sockaddr_in server_address;
    char buffer[1024] = {0};
    struct timeval start, end;

    if (argc < 3) {
        printf("Usage: ./client.out 127.0.0.1 8888\n");
        return 0;
    }

    server = gethostbyname(argv[1]);

    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    gettimeofday(&start, NULL);

    if (connect(client_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed.");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    // send data
    strcpy(buffer, "GET / HTTP/1.1\r\n"
            "Host: www.memcd.com\r\n"
            "User-Agent: client.c\r\n"
            "Accept: */*\r\n");
    send(client_fd, buffer, strlen(buffer), 0);

    int len = read(client_fd, buffer, 1024);
    printf("Received %d bytes: %s\n", len, buffer);

    close(client_fd);

    gettimeofday(&end, NULL);
    int diff = time_diff(&start, &end); 
    printf("time spend: %d us\n", diff);

    return 0;
}