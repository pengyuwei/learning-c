#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h> // for close
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

int init_server(void)
{
    struct sockaddr_in server_addr;
    int listen_fd = 0;
    int qlen = 0;
    int type = SOCK_STREAM;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; // PF_INET
    server_addr.sin_port = htons(12020);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /*
    Server step:
    1. socket
    2. bind
    3. listen
    4. accept
    5. close: client_fd && listen fd 
    */
    listen_fd = socket(server_addr.sin_family, type, 0);
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

    printf("Server: waiting for connections...\n");

    
    while(1) {  // main accept() loop
        struct sockaddr client_addr;
        socklen_t client_addr_len;
        int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
        }

        if (!fork()) {
            // child
            close(listen_fd); // child doesn't need the listener

            struct sockaddr_in *pclient = (struct sockaddr_in *)&client_addr;
            printf("connected %u:%u\n", pclient->sin_addr.s_addr, ntohs(pclient->sin_port));
            if (send(client_fd, "Hello, world!", 13, 0) == -1) {
                perror("send");
            }
            printf("closed %u:%u\n", pclient->sin_addr.s_addr, ntohs(pclient->sin_port));
            close(client_fd);
            exit(0);
        }
        close(client_fd); // parent
    }

    close(listen_fd);
    return 0;
}

int main()
{
    init_server();
    return 0;
}