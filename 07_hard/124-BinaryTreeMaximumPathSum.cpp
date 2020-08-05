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
//   保存最大值得
    int res = INT_MIN;
    int coreDeal(TreeNode *root)
    {
        if(root == nullptr)
        {
            return 0;
        }
//        最左边的最大路径
        int left = max(0, coreDeal(root->left));
//        右边的最大路径
        int right = max(0,coreDeal(root->right));
//        最大路径
        res = max(res, root->val + left + right);
//        返回上一层 左右 只能有一个
        return  max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        coreDeal(root);
        return res;
    }
};


int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    s.maxPathSum(root);
    system("pause");
    return 0;
}