#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-27 题目：镜像二叉树
    请完成一个函数，输入一个二叉树，该函数输出它的镜像。
    例如输入：
        4
      /   \
     2     7
    / \   / \
   1   3 6   9
    镜像输出：
        4
      /   \
     7     2
    / \   / \
    9   6 3   1
    示例 1：
        输入：root = [4,2,7,1,3,6,9]
        输出：[4,7,2,9,6,3,1]
*/

/*
思路：

 */
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr){}
};

// 递归
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
};

// 非递归
class Solution1 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;
            if(node->left){
                que.push(node->left);
            }
            if(node->right){
                que.push(node->right);
            }
        }
        return root;
    }
};

int main(){

    system("pause");
    return 0;
}