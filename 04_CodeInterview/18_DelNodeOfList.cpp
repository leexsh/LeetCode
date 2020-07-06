#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
/*
 * 18-删除链表中的节点
    给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
    返回删除后的链表的头节点。
    注意：此题对比原题有改动
    示例 1:
        输入: head = [4,5,1,9], val = 5
        输出: [4,1,9]
    解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
    示例 2:
        输入: head = [4,5,1,9], val = 1
        输出: [4,5,9]
    解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *p = pre;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return pre->next;
    }
};
int main() {
    cout<<1e5<<endl;
    return -1;
}