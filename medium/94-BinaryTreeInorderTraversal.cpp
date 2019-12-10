#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-94 题目：二叉树的中序遍历
    给定一个二叉树，返回它的中序 遍历。
    示例:
        输入: [1,null,2,3]
        1
         \
          2
         /
        3
        输出: [1,3,2]
        进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
  
/*
思路：
    二叉树的中序遍历 递归和非递归
 */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec;
    if(root == NULL){
        return vec;
    }        
    stack<TreeNode*> s;
    while(!s.empty() || root){
        if(root){
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            vec.push_back(root->val);
            root = root->right;
        }
    }
    return vec;
}


// 递归
void FindNode(TreeNode*root,vector<int>& Node)
{
    if(root == NULL)
        return;
    FindNode(root->left,Node);
    Node.push_back(root->val);
    FindNode(root->right,Node);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec;
    FindNode(root, vec);
    return vec;
}
  

int main(){

    system("pause");
    return 0;
}