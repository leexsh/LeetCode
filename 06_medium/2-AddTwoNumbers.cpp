#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-2 题目：两数相加
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位 数字。
    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    示例：
        输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
        输出：7 -> 0 -> 8
        原因：342 + 465 = 807
*/

/*
思路：

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode(-1);
        ListNode* cur = pre;
        int sum;
        int carray = 0;
        while(l1 || l2)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0 ;
            sum = x + y + carray;
            carray = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carray == 1) {
            cur->next = new ListNode(1);
        }
        return pre->next;
    }
};

int main(){

    system("pause");
    return 0;
}