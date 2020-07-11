#include <iostream>
#include <map>
using namespace std;
//
// Created by leexsh on 2020/7/11.
//

//剑指 Offer 35. 复杂链表的复制
//        请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        map<Node*, Node*> node_map;
        Node* p = head;
        for (; p != nullptr; p = p->next) {
            node_map[p] = new Node(p->val);
        }
        p = head;
        for (; p; p = p->next) {
            node_map[p]->next = node_map[p->next];
        }

        p = head;
        for (; p; p = p->next) {
            node_map[p]->random = node_map[p->random];
        }

        return node_map[head];
    }
};
int main() {


    return 0;
}