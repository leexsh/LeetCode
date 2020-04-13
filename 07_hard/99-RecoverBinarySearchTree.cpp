#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-124 题目：二叉树中最大路径的和
    给定一个非空二叉树，返回其最大路径和。
    本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
    示例 1:
        输入: [1,2,3]
           1
          / \
         2   3
        输出: 6
    示例 2:
        输入: [-10,9,20,null,null,15,7]
       -10
       / \
      9  20
      /  \
     15   7
    输出: 42
*/

/*
思路：

 */

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value),left(nullptr), right(nullptr){}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root){
            return ;
        }
        TreeNode *x = nullptr, *y = nullptr, *pre = nullptr;
        stack<TreeNode*> que;
        while(!que.empty() || root)
        {
            if(root){
                que.push(root);
                root = root->left;
            } else{
                root = que.top();
                que.pop();
                if(pre && root->val < pre->val){
                    y = root;
                    if(x == nullptr)
                        x = pre;
                }
                pre = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};
int main(){

    system("pause");
    return 0;
}