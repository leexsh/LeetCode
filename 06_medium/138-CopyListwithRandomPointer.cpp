#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-138 题目：复制带随机指针的链表
    给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
    要求返回这个链表的深拷贝。 
    示例：
        输入：
            {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
    解释：
        节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
        节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
    提示：
        你必须返回给定头的拷贝作为对克隆列表的引用。
*/

/*
思路：
1.hash map 3.串成一个链表
 */
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

Node* copyRandomList1(Node* head) {
    if(head == NULL){
        return NULL;
    }
    Node *cur = head;
    Node *nextNode = NULL;
    // 拷贝节点  串在一起
    while(cur){
        nextNode = cur->next;
        cur->next = new Node(cur->val, nextNode, NULL);
        cur = nextNode;
    }
    Node* copyNode = NULL;
    cur = head;
    // 拷贝节点的random
    while(cur){
        nextNode = cur->next->next;
        cur->next->random = cur->random?cur->random->next : NULL;
        cur = nextNode;
    }
    cur = head;
    //两个链表分离
    Node *res = cur->next;
    while(cur){
        nextNode = cur->next->next;
        copyNode = cur->next;
        cur->next = nextNode;
        copyNode->next = nextNode?nextNode->next : NULL;
        cur = nextNode;
    }
    return res;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> map;
        Node* p = head;
        for (; p; p = p->next) {
            map[p] = new Node(p->val, nullptr, nullptr);
        }
        p = head;
        for (; p; p = p->next)
        {
            map[p]->next = map[p->next];
            map[p]->random = map[p->random];
        }
        return map[head];
    }
};
class Solution1 {
public:

    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        // create
        Node* p = head;
        while (p) {
            Node* nex = p->next;
            p->next = new Node(p->val, nex, nullptr);
            p = nex;
        }

        // copy random
        p = head;
        while (p) {
            p->next->random = p->random ? p->random->next : nullptr;
            p = p->next->next;
        }

        p = head;
        Node* res = head->next;
        Node* yuanNode = nullptr;
        Node* newNode = nullptr;
        while (p) {
            yuanNode = p->next->next;
            newNode = p->next;
            p->next = yuanNode;
            newNode->next = yuanNode ? yuanNode->next : nullptr;
            p = p->next;
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}