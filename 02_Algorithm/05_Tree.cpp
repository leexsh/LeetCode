#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/7/27.
//
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr){}
};
// 前序遍历 非递归
void preorder(TreeNode* root)
{
    if (!root) {
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        root = st.top();
        st.pop();
        cout<<root->val<<" ";
        if (root->right) {
            st.push(root->right);
        }
        if (root->left) {
            st.push(root->left);
        }
    }
}

// 中序遍历 非递归
void inorder(TreeNode* root)
{
    if (!root) {
        return;
    }
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty() || root) {
        while(root->left) {
            st.push(root->left);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cout<<root->val;
        root = root->right;
    }
}

// 后续遍历 非递归
void postorder(TreeNode *root){
    if (!root) {
        return ;
    }
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while (!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if (root->left) {
            st1.push(root->left);
        }
        if (root->right) {
            st1.push(root->right);
        }
    }
    while(!st2.empty()) {
        cout<<st2.top()<<endl;
        st2.pop();
    }
}
int main() {


    return 0;
}