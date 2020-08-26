// Production-consume生产-消费线程模型
#include <iostream>
#include <pthread.h>

// g++ thread.cpp -lpthread -o thread.out

using namespace std;

#define NUM_THREADS 5
struct thread_data {
    int id;
    char *msg;
};

void* production(void *args)
{
    return 0;
}

void* consume(void *args)
{
    return 0;
}

int main(void)
{
    pthread_t tids[NUM_THREADS];
    struct thread_data data[NUM_THREADS];

    // 生产线程，产生数据
    int ret = pthread_create(&tids[i], NULL, production, (void *)&data[i]);
    if (ret != 0) {
        cout << "create error" << ret << endl;
    }

    // 消费线程，消费数据

    // 等待数据处理完毕

    pthread_exit(NULL);
    
    return 0;
}