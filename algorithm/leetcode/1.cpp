/*
1. Two Sum
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target. You may assume that each input would
have exactly one solution, and you may not use the same element twice. You can
return the answer in any order. Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) {
                    continue;
                }
                int b = nums[j];
                if (a + b == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

void show(vector<int> nums) {
    static int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        printf("%d. %d\n", count, nums[i]);
    }
    count++;
}

void test_case() {
    Solution s;
    vector<int> nums;
    vector<int> ret;

    nums.insert(nums.end(), {2, 7, 11, 5});
    ret = s.twoSum(nums, 9);
    assert(ret[0] == 0);
    assert(ret[1] == 1);

    nums.clear();ret.clear();
    nums.insert(nums.end(), {3, 2, 4});
    ret = s.twoSum(nums, 6);
    assert(ret[0] == 1);
    assert(ret[1] == 2);

    nums.clear();ret.clear();
    nums.insert(nums.end(), {3, 2, 3});
    ret = s.twoSum(nums, 6);
    assert(ret[0] == 0);
    assert(ret[1] == 2);

    nums.clear();ret.clear();
    nums.insert(nums.end(), {3, 3});
    ret = s.twoSum(nums, 6);
    assert(ret[0] == 0);
    assert(ret[1] == 1);
}

int main() {
    test_case();
    return 0;
}
