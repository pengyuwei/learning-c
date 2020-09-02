#include <sys/socket.h>
#include <unistd.h> // for close

int connect(int domain, const struct sockaddr * addr, socklen_t alen)
{
    int type = 0, protocol = 0;
    int fd;

    fd = socket(domain, type, protocol);
    if (fd < 0) {
        return -1;
    }
    if (connect(fd, addr, alen) == 0) {
        return fd;
    }
    close(fd);

    return 0;
}

int main()
{
    struct sockaddr addr;
    addr.sa_family = AF_INET;
    // addr.sa_data = inet_addr("127.0.0.1");

    connect(0, &addr, 0);
    return 0;
}