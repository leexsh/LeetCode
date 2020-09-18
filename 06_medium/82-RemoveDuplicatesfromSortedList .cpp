#include "bits/stdc++.h"
using namespace std;
/*

*/

/*
思路：
82. 删除排序链表中的重复元素 II
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
    示例 1:
        输入: 1->2->3->3->4->4->5
        输出: 1->2->5
    示例 2:
        输入: 1->1->1->2->3
        输出: 2->3
 */
struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* p = new ListNode(-1);
        p->next = head;
        head = p;
        ListNode* L, *R;
        while (p->next) {
            L = p->next;
            R = p->next;
            while (R->next && L->val == R->next->val) {
                R = R->next;
            }
            if (L == R) {
                p = p->next;
            } else {
                p->next = R->next;
            }
        }
        return head->next;
    }
};
int main(){

    system("pause");
    return 0;
}