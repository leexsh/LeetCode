#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-142 题目：环形链表2
    给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
    如果 pos 是 -1，则在该链表中没有环。
    说明：不允许修改给定的链表。
    示例 1：
        输入：head = [3,2,0,-4], pos = 1
        输出：tail connects to node index 1 
        解释：链表中有一个环，其尾部连接到第二个节点。
    示例 2：
        输入：head = [1,2], pos = 0 
        输出：tail connects to node index 0 
        解释：链表中有一个环，其尾部连接到第一个节点。
    示例 3：
        输入：head = [1], pos = -1  
        输出：no cycle
        解释：链表中没有环。
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

class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};
// set
ListNode *detectCycle1(ListNode *head) {
    if(head == NULL){
        return NULL;
    }
    set<ListNode*> s;
    ListNode *cur = head;
    while(cur){
        if(s.count(cur)){
            return cur;
        }
        s.insert(cur);
        cur = cur->next;
    }
    return NULL;
}
// 快慢指针
ListNode *detectCycle2(ListNode *head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return NULL;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
             fast = head;
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
ListNode *detectCycle2(ListNode *head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return NULL;
    }
    ListNode *fast = head->next->next;
    ListNode *slow = head->next;
    while(fast != slow){
        if(fast->next  == NULL && fast->next->next == NULL){
            return NULL;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main(){
    ListNode *p = new ListNode(3);
    p->next = new ListNode(2);
    p->next->next = new ListNode(0);
    p->next->next->next = new ListNode(4);
    p->next->next->next->next = p->next;
    ListNode *pp = detectCycle2(p);
    cout<<p->val<<endl;
    system("pause");
    return 0;
}