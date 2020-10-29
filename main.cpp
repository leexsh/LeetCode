#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k <= 0) {
            return head;
        }
        int size = 1;
        ListNode* p = head;
        while (p->next) {
            p = p->next;
            size++;
        }
        p->next = head;
        int m = size - k % size;
        while (m--) {
            p = p->next;
        }
        ListNode* res= p->next;
        p->next = nullptr;
        return res;
    }
};

