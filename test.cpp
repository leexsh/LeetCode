#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode- 题目：

*/

/*
思路：

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    ListNode *pre = new ListNode(-1);
    pre->next = head;
    ListNode *cur = pre;
    while(head){
        if(head->next && head->val != head->next->val){
            cur = head;
            head = head->next;
        }
        else
        {
            while(head->next && head->val == head->next->val){
                head = head->next;
            }
            cur->next = head->next;
            head = cur->next;
        }
    }
    return pre->next;
}
void test(){
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(1);
    deleteDuplicates(p);
}
int main(){
    test();
    system("pause");
    return 0;
}