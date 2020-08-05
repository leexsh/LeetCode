#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
25. K 个一组翻转链表
    给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。
    如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

    示例：
        给你这个链表：1->2->3->4->5
        当 k = 2 时，应当返回: 2->1->4->3->5
        当 k = 3 时，应当返回: 3->2->1->4->5
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
    ListNode* myReverse(ListNode* head, int k)
    {
        if (k == 1){
            return head;
        }

        ListNode* cur = myReverse(head->next, k-1);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* p = head;
        while(p && count < k) {
            p = p->next;
            count++;
        }
        if (count < k) {
            return head;
        }
        ListNode* newHead = myReverse(head, k);
        head->next = reverseKGroup(p, k);
        return newHead;
    }
};

class Solution1 {
public:
    ListNode* myRevese(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode* res = myRevese(head->next, k-1);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* p = head;
        while (count < k && p)
        {
            count++;
            p = p->next;
        }
        if (count < k) {
            return head;
        }
        ListNode* newHead = myRevese(head, k);
        head->next = reverseKGroup(p, k);
        return newHead;
    }
};

int main(){

    system("pause");
    return 0;
}