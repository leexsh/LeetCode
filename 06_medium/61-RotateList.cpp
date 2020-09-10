#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/4/23.
//

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int value) : val(value), next(nullptr){}
};
class Solution2 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }
        int size = 1;
        ListNode* newnode = head;
        while (newnode->next) {
            newnode = newnode->next;
            size++;
        }
        if (k % size == 0) {
            return head;
        }
        newnode->next = head;
        int m = size - k % size;
        while (m--) {
            newnode = newnode->next;
        }
        ListNode* res = newnode->next;
        newnode->next = nullptr;
        return res;
    }
};
// 借助队列
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
        {
            return nullptr;
        }
        deque<ListNode*> dq;
        ListNode *p = head;
        while (p)
        {
            dq.push_back(p);
            p = p->next;
        }
        int len = dq.size();
        k %= len;
        while (k--)
        {
            ListNode *pp = dq.back();
            dq.pop_back();
            dq.push_front(pp);
        }
        ListNode *pre = new ListNode(-1);
        ListNode *node = pre;
        while (!dq.empty())
        {
            p = dq.front();
            p->next = nullptr;
            dq.pop_front();
            node->next = p;
            node = node->next;

        }
        return pre->next;

    }
};


class Solution1 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
        {
            return nullptr;
        }
        ListNode *p = head;
        int len = 0;
        while (p)
        {
            p = p->next;
            len++;
        }
        k %= len;
        ListNode *fast = head, *slow = head;
        while (k--)
        {
            fast = fast->next;
        }
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;

    }
};
int main() {
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = new ListNode(5);
    Solution s;
    ListNode *node = s.rotateRight(p,2);

    return 0;
}