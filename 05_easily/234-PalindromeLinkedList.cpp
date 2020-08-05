#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-234 题目：回文链表
    请判断一个链表是否为回文链表。
    示例 1:
        输入: 1->2
        输出: false
    示例 2:
        输入: 1->2->2->1
        输出: true
    进阶：
        你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题
*/

/*
思路：

 */
/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 翻转链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *slow, *fast;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* cur = slow;
        ListNode* p = slow->next;
        while (p) {
            ListNode *n = p->next;
            p->next = cur;
            cur = p;
            p = n;
        }
        slow->next = nullptr;
        while (head && cur) {
            if (head->val != cur->val) {
                return false;
            }
            head = head->next;
            cur = cur->next;
        }
        return true;

    }
};


// 栈的方法 时间复杂度O(N) 空间复杂度O(N)
bool isPalindrome1(ListNode* head) {
    stack<ListNode*> s;
    ListNode *p = head;
    while(p){
        s.push(p);
        p = p->next;
    }
    while(head){
        p = s.top();
        s.pop();
        if(head->val != p->val){
            return false;
        }
    }
    return true;
}
// 链表翻转的方法 时间复杂度O(N) 空间复杂度O(1)
bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return true;
    ListNode *p1 = head;//慢指针
    ListNode *p2 = head;//快指针
    while(p2->next && p2->next->next){
    // 快指针一次走两步 慢指针一次一步 若链表奇数个 慢指针走到中点位置 偶数个 慢指针走到中点的前一个位置
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p2 = p1->next;//p2指向了后半部分的第一个节点 要进行逆序的地方
    p1->next = NULL;//p1->next NULL
    ListNode* p3 = NULL;
    while(p2){
        p3 = p2->next;//p3 指向要逆序的下一个
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    p3 = p1;//左半部分链表的第一个节点 一会要将链表正序
    p2 = head;
    bool res = true;
    while(p1 && p2){
        if(p1->val != p2->val){
            res = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    // 逆序回去
    p1 = p3->next;
    p3->next = NULL;
    while(p1){
        p2 = p1->next;
        p1->next = p3;
        p3 = p1;
        p1 = p2;
    }
    return res;
}


int main(){

    system("pause");
    return 0;
}