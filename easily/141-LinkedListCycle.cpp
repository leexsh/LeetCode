#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-141 题目：环形链表
    给定一个链表，判断链表中是否有环。
    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
    如果 pos 是 -1，则在该链表中没有环。

    示例 1：    
        输入：head = [3,2,0,-4], pos = 1
        输出：true
        解释：链表中有一个环，其尾部连接到第二个节点。
    示例 2：
        输入：head = [1,2], pos = 0
        输出：true
        解释：链表中有一个环，其尾部连接到第一个节点。
    示例 3：
        输入：head = [1], pos = -1
        输出：false 
        解释：链表中没有环。
*/

/*
思路：
    见 1,2
 */

//  单链表的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 快慢指针的方式  定一个两个指针 一快一慢 如果是环形链表最终将会相遇
bool hasCycle(ListNode *head) {
    if(head == NULL)
        return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}

// 利用集合的方法 将指针放入集合中
bool hasCycle(ListNode *head) {
    set<ListNode*> s;
    while(head != NULL){
        if(s.count(head))
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}
int main(){

    system("pause");
    return 0;
}