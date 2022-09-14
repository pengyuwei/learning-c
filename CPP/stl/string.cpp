#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    std::string str;
    str = "Hello";
    char c = str[1];
    printf("%c\n", c);
    return 0;
}