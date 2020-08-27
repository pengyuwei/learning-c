#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    int n;
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cin >> n;
    std::cout << "Number is: " << n << std::endl;
    std::cout << "foo is finished........" << std::endl;
}

void bar()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "bar is finished........" << std::endl;
}

int main()
{
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);

    std::cout << "starting second helper...\n";
    std::thread helper2(bar);
    std::cout << "waiting for helpers to finish..." << std::endl;

    helper1.join();
    helper2.join();

    std::cout << "done!\n";
}