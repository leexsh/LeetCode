#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-112 题目：路径总和
    给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
    说明: 叶子节点是指没有子节点的节点。
    示例: 
        给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
    返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。


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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        sum -= root->val;
        if(sum == 0 && !root->left && !root->right){
            return true;
        }
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            root = dq.front();
            dq.pop_front();
            if (root->left == nullptr && root->right == nullptr && root->val == sum) {
                return true;
            }
            if (root->left) {
                root->left->val += root->val;
                dq.push_back(root->left);
            }
            if (root->right) {
                root->right->val += root->val;

                dq.push_back(root->right);
            }
        }
        return false;
    }
};
int main(){

    system("pause");
    return 0;
}