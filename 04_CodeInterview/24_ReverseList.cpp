#include <iostream>

using namespace std;
//
// Created by leexsh on 2020/7/5.
//
/*
    定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
    示例:
        输入: 1->2->3->4->5->NULL
        输出: 5->4->3->2->1->NULL
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr || head == nullptr) {
            return head;
        }
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pHead = nullptr;
        ListNode *next= nullptr;
        while (head) {
            next = head->next;
            head->next = pHead;
            pHead = head;
            head = next;
        }
        return pHead;
    }
};
int main() {

    return 0;
}