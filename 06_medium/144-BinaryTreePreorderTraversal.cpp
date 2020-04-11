#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-144 题目：二叉树的前序遍历
    给定一个二叉树，返回它的 前序 遍历。
    示例:
        输入: [1,null,2,3]  
            1
             \
              2
             /
            3 
        输出: [1,2,3]
    进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

/*
思路：

 */
class TreeNode{
public:
    TreeNode(int v) : val(v), left(nullptr),  right(nullptr){}    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
// 递归
void findNode(TreeNode *head, vector<int> &vec){
    if(head == nullptr){
        return;
    }
    vec.push_back(head->val);
    findNode(head->left, vec);
    findNode(head->right,vec);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    findNode(root, vec);
    return vec;    
}

// 非递归
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    if(root == nullptr){
        return vec;
    }    
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        vec.push_back(root->val);
        if(root->right){s.push(root->right);}
        if(root->left){s.push(root->left);}
    }
    return vec;

}
int main(){

    system("pause");
    return 0;
}