#include <unordered_set>
#include <string>
#include <cstdio>
#include <assert.h>

typedef std::unordered_set<int > UoSet;

std::string set2string(UoSet& set) {
    std::string ret;
    for (UoSet::iterator i = set.begin(); i != set.end(); i++) {
        ret += *i;
    }
    return ret;
}

// c++ -Wall -g -std=c++11 set.cpp -o set.out
int main() {
    UoSet set{1,2,3};

    set.insert(4);
    set.emplace(5);

    for (UoSet::iterator i = set.begin(); i != set.end(); i++) {
        printf("%d\n", *i);
    }
    
    printf("size = %lu\n", set.size());
    printf("bucket_count = %lu\n", set.bucket_count());
    printf("max_bucket_count = %lu\n", set.max_bucket_count());
    printf("bucket_size(3) = %lu\n", set.bucket_size(3));
    printf("bucket(3) = %lu\n", set.bucket(3));
    assert(set.size() == 5);
    assert(set.bucket(3) == 3);
    assert(set.bucket_size(3) == 1);

    UoSet::iterator ret = set.find(3);
    printf("%s find: %d\n", set2string(set).c_str(), *ret);
    UoSet::iterator ret2 = set.find(99);
    assert(ret2 == set.end());
    set.erase(3);
    set.clear();

    return 0;
}