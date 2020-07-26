#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-86 题目：分隔链表
    给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
    你应当保留两个分区中每个节点的初始相对位置。
    示例:
        输入: head = 1->4->3->2->5->2, x = 3
        输出: 1->2->2->4->3->5
*/

/*
思路：

 */
struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return nullptr;
        }
        ListNode* l1 = new ListNode(-1);
        ListNode* l2 = new ListNode(-1);
        ListNode* cur1 = l1, *cur2 = l2;
        ListNode* p = head;

        for (; p != nullptr; p = p->next) {
            if (p->val < x) {
                cur1->next = p;
                cur1 = cur1->next;
            } else {
                cur2->next = p;
                cur2 = cur2->next;
            }
        }
        cur2->next = nullptr;
        cur1->next = l2->next;
        return l1;
    }
};
int main(){
    vector<int> nums;
    int target = 0;
    find(nums.begin(), nums.end(),target);
    system("pause");
    return 0;
}