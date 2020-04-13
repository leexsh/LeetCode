#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-111 题目：二叉树的最小深度
    给定一个二叉树，找出其最小深度。
    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
    说明: 叶子节点是指没有子节点的节点。
    示例:
        给定二叉树 [3,9,20,null,null,15,7],
        3
       / \
      9  20
      /  \
     15   7
    返回它的最小深度  2.

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
    int minDeep = 0;
    int minDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            return 1;
        }
        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth+1;
    }
};
int main(){

    system("pause");
    return 0;
}