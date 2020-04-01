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
int main(){

    system("pause");
    return 0;
}