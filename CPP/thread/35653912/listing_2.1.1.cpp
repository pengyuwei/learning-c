#include <thread>

class background_task {
    public:
        void operator()() const {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            printf("background_task.operator()\n");
        }
};

void oops() {
    background_task task;
    std::thread my_thread(task);
    // std::thread my_thread1(background_task()); // warning: parentheses were disambiguated as a function declaration
    std::thread my_thread2((background_task())); // 防止语句被解释成函数声明
    std::thread my_thread3{background_task()}; // uniform initialization syntax
    std::thread my_thread4([] { // C++11 lambda style
        printf("my_thread4: style of C++11\n");
    });

    my_thread.join();
    my_thread2.join();
    my_thread3.join();
    my_thread4.detach();
}

// g++ -Wall -g -std=c++11 listing_2.1.1.cpp -lpthread
int main() {
    oops();
}
