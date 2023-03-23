#include <thread>

void do_something(int& i) {
    ++i;
}

struct func {
    int& i;

    func(int& i_) : i(i_) {
        printf("Constructor of func:%d\n", i_);
    }

    void operator()() {
        for (unsigned j=0;j<1000000;++j) {
            do_something(i); // Hidden Problems
        }
        printf("%d\n", i);
    }
};


void oops() {
    int some_local_state = 0;
    func my_func(some_local_state); // call constructor of func

    std::thread my_thread(my_func);

    my_thread.detach();
    // my_thread.join();
}

int main() {
    oops();
}
