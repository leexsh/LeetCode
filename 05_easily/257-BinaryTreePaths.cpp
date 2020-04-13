#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-257 题目：二叉树的所有路径
    给定一个二叉树，返回所有从根节点到叶子节点的路径。
    说明: 叶子节点是指没有子节点的节点。
    示例:
        输入:
        1
      /   \
     2     3
     \
      5
    输出: ["1->2->5", "1->3"]
    解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    void preorder(TreeNode *root, vector<string> &nums, string str)
    {
        if(root)
        {
            str += to_string(root->val);
            if(!root->left && !root->right)
            {
                nums.push_back(str);

            } else
            {
                str += "->";
                preorder(root->left, nums,str);
                preorder(root->right, nums, str);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        string str;
        preorder(root,vec,str);
        return vec;
    }
};
int main(){

    system("pause");
    return 0;
}