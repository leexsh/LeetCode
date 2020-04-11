#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-116 题目：填充每个节点的下一个右侧指针

*/

/*
思路：

 */

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<Node *> que;
        que.push(root);
//        root->next = NULL;
        while (!que.empty())
        {
            int size = que.size();
//            int i = 0;
            for(int i = 0; i < size; i++){
                Node *node = que.front();
                que.pop();
                if(i+1 == size){
                    node->next = NULL;
                } else{
                    node->next = que.front();
                }
                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }

        }
        return root;
    }
};

class Solution1 {
public:
    Node* connect(Node* root) {
        if(root == nullptr || root->left == nullptr)
        {
            return root;
        }
        root->left->next = root->right;
        if(root->next){
            root->right->next = root->next->left;
        }
        root->left = connect(root->left);
        root->right = connect(root->right);
        return root;

    }
};
int main(){

    system("pause");
    return 0;
}