#include <stdio.h>
#include <utility>
using namespace std;

void automatic_derivation() {
    // pair<int, double> p(1, 2.2); // before c++17
    std::pair p(1, 3.14); // 自动类型推导
    printf("%d, %.01f\n", p.first, p.second);
}

int main() {
    automatic_derivation();
}