#include"bits/stdc++.h"
using namespace std;
/* 
LeetCode21 -合并两个有序链表：
    将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

    示例：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4
*/

/*
思路：
    定义一个新的头结点 将两个有序的链表从小到大串起来
 */
struct ListNode{
    int var;
    ListNode *next;
    ListNode(int x): var(x), next(NULL){}
};

// 非递归的实现方式
ListNode *mergeTwoList(ListNode *l1, ListNode *l2){
    // 申请一个头结点
    ListNode *p = new ListNode(0);
    // 尾指针 永远指向p链表的最后一个节点
    ListNode *pTemp = p;

    // 比较两个数的大小
    while(l1 && l2){
        if(l1->var < l2->var){
            pTemp->next = l1;
            l1 = l1->next;
            pTemp = pTemp->next;
        }
        else{
            pTemp->next = l2;
            l2 = l2->next;
            pTemp = pTemp->next;
        }
    }
    //比较结束后 将非空的链表接上
    pTemp->next = l1 ? l1 : l2;

    return p->next;
}

//递归的实现方式
ListNode *mergeTwoListsRec(ListNode *l1, ListNode *l2){
    // l1空 返回l1 l2空 返回l2
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    // l1 比 l2小 再进行递归比较  反之 相同 返回的是l1或l2节点 
    if(l1->var < l2->var){
        mergeTwoListsRec(l1->next, l2);
        return l1;
    }
    else{
        mergeTwoListsRec(l1, l2->next);
        return l2;
    }
}

int main(){
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    p->next->next = new ListNode(4);

    ListNode *q = new ListNode(1);
    q->next = new ListNode(2);
    q->next->next = new ListNode(3);

    ListNode *temp = mergeTwoList(p, q);

    while(temp){
        cout<<temp->var<<" ";
        temp = temp->next;
    }
    system("pause");
    return 0;
}