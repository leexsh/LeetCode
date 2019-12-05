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
Node* copyRandomList(Node* head) {
    if(head == NULL){
        return NULL;
    }
    unordered_map<Node*, Node*> m;
    Node *cur = head;
    
    while(cur){
        m[cur] = new Node(cur->val, NULL, NULL);
        cur = cur->next;
    }
    cur = head;
    while(cur){
        m[cur]->next = m[cur->next];
        m[cur]->random = m[cur->random];
        cur = cur->next;
    }
    return m[head];
}

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
int main(){

    system("pause");
    return 0;
}