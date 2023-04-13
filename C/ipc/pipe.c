#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PIPE_READ 0
#define PIPE_WRITE 1


int main() {
    int fd[2] = {0};
    pid_t pid = 0;
    char buf[1024] = {0};

    // 创建管道
    // fd[0]:从管道中读取; fd[1]: 向管道中写入
    if (pipe(fd) < 0) {
        fprintf(stderr, "Pipe Creation Failed.\n");
        return 1;
    }

    // fork 子进程
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed.\n");
        return 1;
    } else if (pid == 0) {
        // 子进程
        close(fd[PIPE_WRITE]);
        read(fd[PIPE_READ], buf, sizeof(buf));
        printf("SubProcess Received Message: %s\n", buf);
        close(fd[PIPE_READ]);
    } else {
        // 父进程
        close(fd[PIPE_READ]);
        const char *msg = "Hello World!\n";
        write(fd[PIPE_WRITE], msg, strlen(msg));
        close(fd[PIPE_WRITE]);
        wait(NULL);
    }

    return 0;
}