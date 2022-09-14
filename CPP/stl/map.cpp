#include <map>
#include <string>

using namespace std;
typedef std::map<string, int> Type;

void find(Type &data, const char* key) {
    Type::iterator f = data.find(key);
    if (f != data.end()) {
        printf("find: %s=%d\n", key, f->second);
    } else {
        printf("find: %s not found\n", key);
    }
}

int main(int argc, char *argv[]) {
    std::map<string, int> buf;

    buf.insert(std::pair<string, int>("score", 100));
    buf["count"] = 200;
    buf["temp"] = -1;

    buf.erase("temp");

    for (std::map<string, int>::iterator itor = buf.begin(); itor != buf.end(); itor++)
    {
        printf("init: %s=%d\n", itor->first.c_str(), itor->second);
    }

    string key("score");
    find(buf, key.c_str());
    find(buf, "score1");
    
    return 0;
}