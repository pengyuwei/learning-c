#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/shm.h>

int main(int argc, char * argv[])
{
    int shmid = 0;
    void *shm = NULL;
    int counter = 0;

    shmid = shmget((key_t)1, sizeof(int), 0666|IPC_CREAT);
    shm = shmat(shmid, (void*)0, 0);
    
    counter = *((int *)shm);
    printf("%d\n", counter);

    return 0;
}