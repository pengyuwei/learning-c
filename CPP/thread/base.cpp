#include <iostream>
#include <pthread.h>

// g++ thread.cpp -lpthread -o thread.out

using namespace std;

#define NUM_THREADS 5
struct thread_data {
    int id;
    char *msg;
};

void* say_hello(void *args)
{
    struct thread_data *data = (struct thread_data *)args;
    cout << "Hello:" << data->id << endl;
    return 0;
}

int main(void)
{
    pthread_t tids[NUM_THREADS];
    struct thread_data data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        // pthread_create (thread, attr, start_routine, arg) 
        data[i].id = i;
        data[i].msg = NULL;
        int ret = pthread_create(&tids[i], NULL, say_hello, (void *)&data[i]);
        if (ret != 0) {
            cout << "create error" << ret << endl;
        }
        /* code */
    }
    pthread_exit(NULL);
    
    return 0;
}