#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode- 题目：删除链表的倒数第n个节点
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
    示例：
        给定一个链表: 1->2->3->4->5, 和 n = 2.
        当删除了倒数第二个节点后，链表变为 1->2->3->5.、
    说明：
        给定的 n 保证是有效的。
*/

/*
思路：
    见法1 法2
 */
// Definition for singly-linked list. 
struct ListNode {     
    int val;     
    ListNode *next;     
    ListNode(int x) : val(x), next(NULL) {}
};
// 法1 删除倒数第n个  就是正数size - n个 添加个头结点 方便处理第一个节点
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode *p = head;
    while(p){
        size++;
        p = p->next;
    }
    ListNode *pre = new ListNode(-1);
    pre->next = head;
    int num = size - n;
    p = pre;
    while(num){
        p = p->next;
        num--;
    }
    p->next = p->next->next;
    return pre->next;
}

// 方法2 快慢指针 快指针先从pre+1走n + 1个节点 然后快慢指针一起走 
// 快指针走到头 慢指针正好走到删除节点的前一个 删除就可以
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *pre = new ListNode(-1);
    pre->next = head;
    ListNode *fast = pre;
    ListNode *slow = pre;
    while(n +1){
        fast = fast->next;
        n--;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return pre->next;
}
int main(){

    system("pause");
    return 0;
}