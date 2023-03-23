#include <iostream>
#include <thread>
#include <chrono>

void hello() {
    std::cout<<"Hello1\n";
}

void hello2() {
    std::cout<<"begin hello2\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"end hello2\n";
}

int main() {
    std::thread t(hello);
    std::thread t2(hello2);

    t.join();
    t2.join();
}
