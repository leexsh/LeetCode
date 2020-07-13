#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
剑指 Offer 52. 两个链表的第一个公共节点
输入两个链表，找出它们的第一个公共节点。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode *node = headA;
        int len1 = 0, len2 = 0;
        while (node) {
            len1++;
            node = node->next;
        }
        node = headB;
        while (node) {
            len2++;
            node = node->next;
        }
        ListNode *p;
        if (len1 > len2) {
            int gap = len1 - len2;
            node = headA;
            while (gap) {
                node = node->next;
                gap--;
            }
            p = headB;
        }else {
            int gap = len2 - len1;
            node = headB;
            while(gap) {
                node = node->next;
                gap--;
            }
            p = headA;
        }
        while (p != node) {
            p = p->next;
            node = node->next;
        }
        return p;
    }
};
int main(){

    system("pause");
    return 0;
}