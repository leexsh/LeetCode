#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        ListNode *pre = new ListNode(-1);
        ListNode *node = pre;
        while(l1 && l2){
            if(l1->val < l2->val)
            {
                node->next = l1;
                node = node->next;
                l1 = l1->next;
            } else{
                node->next = l2;
                node = node->next;
                l2 = l2->next;
            }
        }
        if(l1){
            node->next = l1;
        }
        if(l2)
        {
            node->next = l2;
        }
        return pre->next;
    }
};




class Solution1 {
public:

    ListNode *mergeTwoList(ListNode *l1, ListNode *l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->val < l2->val){
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        } else{
            l2->next = mergeTwoList(l1,l2->next);
            return l2;
        }
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return nullptr;
        }
        int len = lists.size();
        while (len > 1)
        {
            int i;
            for(i = 0; i < len /2; i++)
            {
                lists[i] = mergeTwoList(lists[2*i], lists[2*i+1]);
            }

            if(len % 2 != 0)
            {
                lists[i] = lists[len - 1];
                len++;
            }
            len /= 2;
        }
        return lists[0];
    }
};

int main() {
    priority_queue<int,vector<int>,greater<int>> que;

    que.push(3);
    que.push(6);
    que.push(2);
    que.push(1);
    while(!que.empty())
    {
        cout<<que.top();
        que.pop();
    }

    return 0;
}