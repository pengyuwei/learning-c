#include <thread>

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_):
    t(t_) {
        
    }

    ~thread_guard() {
        if(t.joinable()) {
            t.join();
        }
    }
    // 这里把拷贝构造函数和等号运算符声明为删除函数，防止编译器自动生成这两个函数而导致不可预测的行为
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

void do_something(int& i) {
    ++i;
}

struct func {
    int& i;

    func(int& i_):i(i_){}

    void operator()() {
        for(unsigned j=0;j<1000000;++j) {
            do_something(i);
        }
    }
};

void do_something_in_current_thread() {
    printf("do_something_in_current_thread\n");
}

void f() {
    int some_local_state;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
        
    do_something_in_current_thread();
}

int main() {
    f();
}
