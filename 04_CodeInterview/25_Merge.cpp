#include "bits/stdc++.h"
using namespace std;
/*
LeetCode- 题目：
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
    示例1：
        输入：1->2->4, 1->3->4
        输出：1->1->2->3->4->4

*/

/*
思路：

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode(-1);
        ListNode* p = pre;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
        return pre->next;

    }
};
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *p = nullptr;
        if (l1->val < l2->val) {
            p = l1;
            p->next = mergeTwoLists(l1->next, l2);
        } else {
            p = l2;
            p->next = mergeTwoLists(l1, l2->next);
        }
        return p;
    }
};
int main(){

    system("pause");
    return 0;
}