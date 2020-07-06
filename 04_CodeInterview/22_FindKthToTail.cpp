#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
/*
剑指 Offer 22. 链表中倒数第k个节点
    输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
    示例：
        给定一个链表: 1->2->3->4->5, 和 k = 2.
        返回链表 4->5.
 * */

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) :val(value), left(nullptr), right(nullptr){}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head || k < 0) {
            return nullptr;
        }
        ListNode *node = head;
        while (k) {
            node = node->next;
            k--;
        }
        ListNode *res = head;
        while (node) {
            node = node->next;
            res = res->next;
        }
        return res;
    }
};
int main() {
    cout<<1e5<<endl;
    return -1;
}