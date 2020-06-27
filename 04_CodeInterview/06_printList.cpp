#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-06 题目：从头到尾打印
    输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
    示例 1：
        输入：head = [1,3,2]
        输出：[2,3,1]
*/

/*
思路：

 */
class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int value) : val(value), next(nullptr)
    {

    }
};

// 借助辅助栈结构
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int > st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        vector<int> vec;
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};


class Solution1 {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if (!head) {
            return res;
        }
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};
ListNode *reverseList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode *res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
}

ListNode *reverList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *node = head;
    while(node)
    {
        ListNode *next = node->next;
        node->next = pre;

        pre = node;
        node = node->next;
    }
    return pre;
}
int main(){

    system("pause");
    return 0;
}