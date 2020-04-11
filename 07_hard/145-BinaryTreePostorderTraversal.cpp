#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-145 题目：二叉树的后序遍历
    给定一个二叉树，返回它的后序遍历。
    示例:
        输入: [1,null,2,3]  
            1
             \
              2
             /
            3 
        输出: [3,2,1]
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
    二叉树的后序遍历 递归和非递归
 */
// 递归
void addNode(TreeNode *head, vector<int>& nums){
    if(head == NULL){
        return;
    }
    addNode(head->left, nums);
    addNode(head->right, nums);
    nums.push_back(head->val);
}
vector<int> postorderTraversal1(TreeNode* root) {
    vector<int> vec;
    addNode(root, vec);
    return vec;        
}

// 非递归方法1 两个栈
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    if(root == NULL){
        return vec;
    }
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        s2.push(root);
        if(root->left){
            s1.push(root->left);
        }
        if(root->right){
            s1.push(root->right);
        }
    }
    while(!s2.empty()){
        root = s2.top();
        s2.pop();
        vec.push_back(root->val);
    }
    return vec;
}
// 非递归方法2 一个栈
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    if(root == NULL){
        return vec;
    }
    stack<TreeNode*> s;
    TreeNode *pMark = NULL;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            root = root->left;
        }
        if(s.top()->right == NULL || s.top()->right == pMark){
            pMark = s.top();
            s.pop();
            vec.push_back(pMark->val);
        }
        else
        {
            root = s.top()->right;
        }   
    }
    return vec;
}
int main(){

    system("pause");
    return 0;
}