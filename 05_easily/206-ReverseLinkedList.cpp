#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-206 题目：翻转链表
    反转一个单链表。
    示例:
        输入: 1->2->3->4->5->NULL
        输出: 5->4->3->2->1->NULL
    进阶:
        你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

/*
思路：

 */
class ListNode{
public:
    ListNode(int v) : val(v), next(NULL){}
public:
    int val;
    ListNode *next;
};
//头插法
ListNode* reverseList1(ListNode* head) {
    ListNode *pre = new ListNode(-1);
    ListNode *pNext = NULL;
    while(head){
        pNext = head->next;
        head->next = pre->next;
        pre->next = head;
        head = pNext;
    }
    return pre->next;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = nullptr;
        while(head) {
            ListNode* next = head->next;
            head->next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
};

//递归
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;

}
int main(){

    system("pause");
    return 0;
}