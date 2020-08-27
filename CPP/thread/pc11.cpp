/*
C++11的Production-consume生产-消费线程模型
-----
| 1 | <-- consume remove data: -
-----
| 2 |
-----
| 3 | <-- production add data: +
-----
*/
#include <iostream>
#include <thread>
#include <vector>
#include <deque>
#include <mutex>
#include <chrono>
#include <stdexcept>

using namespace std;
std::deque<int> data;
std::mutex mtx; // 保护counter
bool running;
int consume_count = 0;

void production(int count) {
    for (int i = 0; i < count; i++) {
        mtx.lock();
        data.push_back(0xFF);
        cout << "production:" << i + 1 << " buffer:" << data.size() << endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    running = false;
}

void consume(int count) {
    while (running)
    {
        mtx.lock();
        
        if (data.size() > 0) {
            data.pop_front();
            consume_count++;
            cout << "consume " << consume_count << endl;
        }
        
        mtx.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    // TODO: 确认所有数据都处理完了
}

int main(int argc, char* argv[]) {
    running = true;
    std::thread tp(production, 1000);
    std::thread tc(consume, NULL);
    tp.join();
    tc.join();
    std::cout << "Total consume count:" << consume_count << std::endl;
    return 0;
}