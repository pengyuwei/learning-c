/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <cstddef>
#include <stdio.h>
#include <vector>
#include <assert.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* node1, ListNode* node2) {
        ListNode *root = new ListNode();
        ListNode *cur = root;
        ListNode *ret = NULL;
        int carry = 0; // 进位
        int v1 = 0, v2 = 0;
        printf("addTwoNumbers:\n");
        while (node1 != NULL || node2 != NULL || carry) {
            cur->next = new ListNode();
            cur = cur->next;
            v1 = node1 != NULL ? node1->val : 0;
            v2 = node2 != NULL ? node2->val : 0;
            int sum = v1 + v2 + carry;
            printf("\t%d+%d+%d = %d\n",v1, v2, carry, sum);
            carry = sum / 10;
            sum = sum % 10;
            cur->val = sum;
            node1 = node1 == NULL ? NULL : node1->next;
            node2 = node2 == NULL ? NULL : node2->next;
        }

        ret = root->next;
        delete root;
        root = NULL;
        
        return ret;
    }

    // in: [2,4,3]
    // out: 342
    long long getReverseNum(ListNode* node) {
        long long ret = 0;
        long long pos = 1;
        while (true) {
            ret = ret + node->val * pos;
            // printf("getReverseNum:%d*%lld-->%lld\n", node->val, pos, ret);
            if (NULL == node->next) {
                break;
            } else {
                pos *= 10;
                node = node->next;
            }
        }
        // printf("-->%lld\n", ret);
        
        return ret;
    }

    void checkAssert(ListNode* node, vector<int> val) {
        ListNode* me = node;
        for (size_t i = 0; i < val.size(); i++) {
            printf("checkAssert: %d --> %d\n", val[i], me->val);
            assert(val[i] == me->val);
            me = me->next;
        }
        assert(me == NULL);
    }

    void initNode(ListNode* node, vector<int> val) {
        ListNode* me = node;
        for (size_t i = 0; i < val.size(); i++) {
            me->val = val[i];
            me->next = NULL;
            if (i != val.size() - 1) {
                struct ListNode *new_node = new struct ListNode;
                me->next = new_node;
                me = new_node;
            }
        }
    }

    void freeNode(ListNode* node) {
        if (node->next != NULL) {
            freeNode(node->next);
        }
        delete node;
        node = NULL;
    }
};

void test_case1() {
    Solution s;
    ListNode *node1 = new ListNode(); 
    ListNode *node2 = new ListNode(); 
    struct ListNode *node = NULL;

    printf("-------- test_case1 ------------\n");

    s.initNode(node1, {2, 4, 3});
    s.initNode(node2, {5, 6, 4});
    assert(s.getReverseNum(node1) == 342);
    assert(s.getReverseNum(node2) == 465);

    node = s.addTwoNumbers(node1, node2);
    s.checkAssert(node, {7, 0, 8});

    s.freeNode(node);
    s.freeNode(node1);
    s.freeNode(node2);
    node = NULL;
    node1 = NULL;
    node2 = NULL;
}

void test_case2() {
    Solution s;
    ListNode *node1 = new ListNode(); 
    ListNode *node2 = new ListNode(); 
    struct ListNode *node = NULL;

    printf("-------- test_case2 ------------\n");

    s.initNode(node1, {0});
    s.initNode(node2, {0});
    assert(s.getReverseNum(node1) == 0);
    assert(s.getReverseNum(node2) == 0);

    node = s.addTwoNumbers(node1, node2);
    s.checkAssert(node, {0});

    s.freeNode(node);
    s.freeNode(node1);
    s.freeNode(node2);
    node = NULL;
    node1 = NULL;
    node2 = NULL;
}

void test_case3() {
    Solution s;
    ListNode *node1 = new ListNode(); 
    ListNode *node2 = new ListNode(); 
    struct ListNode *node = NULL;

    printf("-------- test_case3 ------------\n");
    s.initNode(node1, {9,9,9,9,9,9,9});
    s.initNode(node2, {9,9,9,9});
    assert(s.getReverseNum(node1) == 9999999);
    assert(s.getReverseNum(node2) == 9999);

    node = s.addTwoNumbers(node1, node2);
    s.checkAssert(node, {8,9,9,9,0,0,0,1});

    s.freeNode(node);
    s.freeNode(node1);
    s.freeNode(node2);
    node = NULL;
    node1 = NULL;
    node2 = NULL;
}

void test_case4() {
    Solution s;
    ListNode *node1 = new ListNode(); 
    ListNode *node2 = new ListNode(); 
    struct ListNode *node = NULL;

    printf("-------- test_case3 ------------\n");
    s.initNode(node1, {9,9,9,9,9,9,9,9,9,9});
    s.initNode(node2, {9,9,9,9});
    assert(s.getReverseNum(node1) == 9999999999);
    assert(s.getReverseNum(node2) == 9999);

    node = s.addTwoNumbers(node1, node2);
    s.checkAssert(node, {8,9,9,9,0,0,0,0,0,0,1});

    s.freeNode(node);
    s.freeNode(node1);
    s.freeNode(node2);
    node = NULL;
    node1 = NULL;
    node2 = NULL;
}

void test_case() {
    long long a = 9*1000000000L+999999999L;
    assert(a == 9999999999L);
}

// c++ -Wall -g -std=c++11 2.cpp -o 2.out
int main() {
    test_case();
    test_case1();
    test_case2();
    test_case3();
    test_case4();
    return 0;
}