#include "assert.h"
#include "leap.h"

namespace leap {
    bool is_leap_year(int year) {
        if (year % 400 == 0) {
            return true;
        }
        if (year % 4 == 0) {
            if (year % 100 != 0) {
                return true;
            }
        }
        return false;
    }
    
}  // namespace leap

int main() {
    assert(leap::is_leap_year(1900)==false);
    assert(leap::is_leap_year(1996)==true);
    assert(leap::is_leap_year(2000)==true);
    assert(leap::is_leap_year(2022)==false);
}