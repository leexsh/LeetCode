#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

/*
思路：

 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* nerw = new ListNode(-1);
        ListNode* pre = nerw;
        pre->next = head;
        ListNode* p = pre->next;
        ListNode* mark1, *mark2;
        while (p && p->next) {
            mark1 = p->next;
            mark2 = p->next->next;
            p->next->next = p;
            p->next = mark2;
            pre->next = mark1;
            pre = p;
            p = mark2;

        }
        return nerw->next;
    }
};
int main(){

    system("pause");
    return 0;
}