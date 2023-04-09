/*
3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Rank 3,684,591

Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.

Accepted 4.4M Submissions 13M Acceptance Rate 33.8%
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <assert.h>

using namespace std;
typedef std::unordered_set<int > UoSet;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t maxlen = 0;
        size_t start = 0;
        UoSet set;

        printf("------------ %s ---------------\n", s.c_str());
        for (size_t i = 0; i < s.size(); i++) {
            printf("%c\n", s[i]);
            UoSet::iterator iter = set.find(s[i]);
            printf("\t%lu. finding repeating: len=%lu\n", i, maxlen);
            if (iter != set.end()) {
                size_t len = i - start;
                start = i;
                maxlen = max(maxlen, len);
                set.erase(iter);
                printf("\t%lu. found: %c[%lu] set=%s\n", i, *iter, maxlen, set2string(set).c_str());
            }
            set.emplace(s[i]);
            printf("\tset=%s\n", set2string(set).c_str());

        }
        printf("\t--> %lu \n", maxlen);
        
        return maxlen;
    }

    string set2string(UoSet& set) {
        string ret;
        for (UoSet::iterator i = set.begin(); i != set.end(); i++) {
            ret += *i;
        }
        return ret;
    }
};

void test_case1() {
    Solution s;
    int ret = 0;
    ret = s.lengthOfLongestSubstring("abcabcbb");
    assert(ret == 3);
    ret = s.lengthOfLongestSubstring("bbbbb");
    assert(ret == 1);
    ret = s.lengthOfLongestSubstring("pwwkew");
    assert(ret == 3);
}

// c++ -Wall -g -std=c++11 3.cpp -o 3.out
int main() {
    test_case1();
    return 0;
}