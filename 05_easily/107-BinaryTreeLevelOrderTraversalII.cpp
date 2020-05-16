#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-107 题目：二叉树的层次遍历II
    给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
    例如：
        给定二叉树 [3,9,20,null,null,15,7],
            3
           / \
          9  20
          /  \
         15   7
        返回其自底向上的层次遍历为：
        [
            [15,7],
            [9,20],
            [3]
        ]
*/

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
思路：

 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
        {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        stack<vector<int>> st;
        while (!dq.empty())
        {
            int size = dq.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = dq.front();
                dq.pop_front();
                temp.push_back(node->val);
                if(node->left)
                {
                    dq.push_back(node->left);
                }
                if(node->right){
                    dq.push_back(node->right);
                }
            }
            st.push(temp);
            temp.clear();
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}