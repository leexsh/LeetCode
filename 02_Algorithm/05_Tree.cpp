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
int main() {


    return 0;
}