#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-34 题目：二叉树中路径
    输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
    示例:
        给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
    返回:
    [
        [5,4,11,2],
        [5,8,4,5]
    ]
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

class Solution {
private:
    vector<vector<int>> res;
    vector<int> num;
public:
    void coreDeal(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> num)
    {
        num.push_back(root->val);
        if(root->val == sum && !root->left && !root->right)
        {
            res.push_back(num);
        }
        if(root->left){
            coreDeal(root->left, sum -root->val, res, num);
        }
        if(root->right)
        {
            coreDeal(root->right, sum - root->val, res, num);
        }
        num.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
        {
            return vector<vector<int>>();
        }
        coreDeal(root, sum, res,num);
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}