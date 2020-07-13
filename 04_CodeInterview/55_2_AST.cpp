#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
剑指 Offer 55 - II. 平衡二叉树
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。



示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

*/

/*
思路：

 */
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left) - getHeight(root->right)) < 2;
    }
    int getHeight(TreeNode* root){
        if (!root) {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return max(left, right) + 1;
    }
};
int main(){

    system("pause");
    return 0;
}