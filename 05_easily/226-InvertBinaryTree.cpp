#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-226 题目：翻转二叉树
    翻转一棵二叉树。
    示例：
        输入：
            4
          /   \
         2     7
        / \   / \
       1   3 6   9
        输出：
           4
         /   \
        7     2
       / \   / \
      9   6 3   1
*/

/*
思路：
    递归
 */
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return  root;
    }
};
int main(){

    system("pause");
    return 0;
}