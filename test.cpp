#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode- 题目：

*/

/*
思路：

 */

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *p = head;
    int size = 0;
    while(p){
        size++;
        p = p->next;
    }
    ListNode *pre = new ListNode(-1);
    pre->next = head;
    p = pre;
    int num = size - n;
    while(num){
        p = p->next;
        num--;
    }
    p->next = p->next->next;
    return pre->next;
}
int main(){

    system("pause");
    return 0;
}