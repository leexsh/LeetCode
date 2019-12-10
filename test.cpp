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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *pre = new ListNode(-1);
    ListNode *cur = pre;
    int sum = 0;
    int carry = 0;
    while(l1 || l2){
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        sum = x + y + carry;
        carry = sum / 10;
        sum = sum % 10;
        cur->next = new ListNode(sum);
        cur = cur->next;
        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
    }
    if(carry){
        cur->next = new ListNode(carry);
    }
    return pre->next;
}
int main(){
    // test();
    system("pause");
    return 0;
}