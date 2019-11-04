#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode -83题目：删除链表中的重复元素
    给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
    示例 1:
        输入: 1->1->2
        输出: 1->2
    示例 2:
        输入: 1->1->2->3->3
        输出: 1->2->3
*/

/*
思路：
    如果两个数相等， 第一个的next指针就往后指一个， 一直到不等。要delete掉重复元素。
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 
 ListNode* deleteDuplicates(ListNode* head) {
     if(head == NULL)
        return NULL;
    ListNode *p = head, *pDel;
    while(p && p->next){
        if(p->val == p->next->val){
            pDel = p->next;
            p->next = pDel->next;
            delete pDel;
        }
        else
        {
            p = p->next;
        }   
    }
    return head;
 }
 
int main(){
    ListNode *l1 =new ListNode(1);
    ListNode *l2 =new ListNode(1);
    ListNode *l3 =new ListNode(2);
    ListNode *l4 =new ListNode(3);
    ListNode *l5 =new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode *p = l1;
    deleteDuplicates(l1);
    while (p)
    {
        /* code */
        cout<<p->val<<" ";
        p = p->next;
    }
    
    system("pause");
    return 0;
}