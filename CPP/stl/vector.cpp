#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

typedef std::vector<std::string> Vect;
Vect vect;

void init() {
}

size_t add() {
    vect.push_back(std::string("1"));
    vect.push_back(std::string("2"));
    vect.push_back(std::string("3"));
    vect.push_back(std::string("End"));
    vect.insert(vect.begin(), "0");
    return vect.size();
}

size_t delete_elements() {
    vect.pop_back(); // remove "End"
    vect.erase(vect.begin()); // remove "0"
    vect.erase(vect.begin() + 1); // remove "2"
    return vect.size();
}

std::string use() {
    std::string var = vect[0];
    return var;
}

void sort_vector() {
    std::vector<int> var;
    var.push_back(2);
    var.push_back(3);
    var.push_back(1);
    var.push_back(-9);
    sort(var.begin(), var.end()); // 从小到大
    for (std::vector<int>::iterator iter = var.begin(); iter != var.end(); iter++) {
        printf("%d\n", *iter);
    }
}

void iteration() {
    for (Vect::iterator iter = vect.begin(); iter != vect.end(); iter++) {
        printf("%s\n", (*iter).c_str());
    }
}

size_t clean() {
    vect.clear();
    return vect.size();
}

size_t deleting_elements_during_iteration() {
    for (Vect::iterator iter = vect.begin(); iter != vect.end(); iter++) {
        std::string var = *iter;
        if (var == "1") {
            iter = vect.erase(iter);
            if (iter == vect.end()) {
                break;
            }
            continue;
        }
    }
    return vect.size();
}

int main() {
    size_t nret = 0;
    init();

    nret = add();
    assert(nret == 5);

    iteration();

    nret = delete_elements();
    assert(nret == 2);
    
    std::string ret = use();
    assert(ret.compare("1") == 0);

    nret = deleting_elements_during_iteration();
    assert(nret == 1);

    nret = clean();
    assert(nret == 0);
}
