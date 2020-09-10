#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-23 题目：合并k个有序链表

*/

/*
思路：

 */
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr)
    {

    }
};
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
        return nullptr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        int len = lists.size();
        while (len > 1) {
            int i;
            for (i = 0; i < len / 2; ++i) {
                lists[i] = merge(lists[2*i], lists[2*i+1]);
            }
            if (len & 1) {
                lists[i] = lists[len - 1];
                len++;
            }
            len /= 2;
        }
        return lists[0];
    }
};
bool com(int a, int b)
{
    return a > b;
}
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        if(lists.empty())
        {
            return nullptr;
        }
        for(auto i : lists)
        {
            ListNode *p = i;
            while (p)
            {
                v.push_back(p->val);
                p = p->next;
            }
        }
        sort(v.begin(), v.end(), com);
        ListNode *head = new ListNode(-1);
        for (int i : v) {
            ListNode *node = new ListNode(i);
            node->next = head->next;
            head->next = node;
        }
        return head->next;
    }
};

// 分治解法 先合并两个
class Solution1 {
public:

    ListNode *mergeTwoList(ListNode *l1, ListNode *l2){
        // 申请一个头结点
        ListNode *p = new ListNode(0);
        // 尾指针 永远指向p链表的最后一个节点
        ListNode *pTemp = p;

        // 比较两个数的大小
        while(l1 && l2){
            if(l1->val < l2->val){
                pTemp->next = l1;
                l1 = l1->next;
                pTemp = pTemp->next;
            }
            else{
                pTemp->next = l2;
                l2 = l2->next;
                pTemp = pTemp->next;
            }
        }
        //比较结束后 将非空的链表接上
        pTemp->next = l1 ? l1 : l2;

        return p->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        {
            return nullptr;
        }
        int len = lists.size();
        while(len > 1)
        {
            int i;
            for(i =0; i < len/2; ++i)
            {
                lists[i] = mergeTwoList(lists[2*i], lists[2*i + 1]);
            }

            if(len % 2 != 0){
                lists[i] = lists[len - 1];
                len++;
            }
            len /= 2;
        }
        return lists[0];
    }
};


// 优先队列解法
class Solution3 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,greater<pair<int, ListNode* >>> m;
        int k = 0;
        for(auto i : lists)
        {
            if(i){
                m.push(make_pair(i->val, i));
            }
//            m.push(make_pair(i->val, i));
        }
        ListNode *root = new ListNode(-1);
        ListNode *p = root;
        while(!m.empty())
        {
            auto node = m.top();
            m.pop();
            p->next = node.second;
            p = p->next;
            if(node.second->next)
            {
                m.push(make_pair(node.second->next->val, node.second->next));
            }
        }
        return root->next;
    }
};

int main(){
    vector<int> v{12,5,83,446,8,21,3,5};
    sort(v.begin(), v.end(),com);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}