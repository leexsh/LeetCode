#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-146 题目：排序链表
    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
    示例 1:
        输入: 4->2->1->3
        输出: 1->2->3->4
    示例 2：
        输入: -1->5->3->4->0
        输出: -1->0->3->4->5
*/

/*
思路：

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool cmp(int a, int b){
    return a > b;
}
// 数组
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        sort(vec.begin(), vec.end(),cmp);
        ListNode *root = new ListNode(-1);
        for(auto i : vec){
            ListNode *node  = new ListNode(i);
            node->next = root->next;
            root->next = node;
        }
        return root->next;
    }
};

// 二路归并方式

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* merge1(ListNode* l1, ListNode* l2){
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* pre = new ListNode(-1);
        ListNode* res = pre;
        while (l1 && l2)
        {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;

            }else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        while(l1) {
            pre->next = l1;
            l1 = l1->next;

            pre = pre->next;
        }
        while (l2) {
            pre->next = l2;
            l2 = l2->next;
            pre = pre->next;
        }
        return res->next;
    }
    ListNode* merge2(ListNode* l1, ListNode* l2)
    {
        if (!l2) {
            return l1;
        }
        if (!l1) {
            return l2;
        }
        while (l1  && l2) {
            if (l1->val < l2->val) {
                l1->next = merge2(l1->next, l2);
                return l1;
            }else {
                l2->next = merge2(l1, l2->next);
                return l2;
            }
        }

        return nullptr;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pre_mid;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast&&fast->next) {
            pre_mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre_mid->next = nullptr;
        return merge1(sortList(head), sortList(slow));
    }
};
int main(){

    system("pause");
    return 0;
}