#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-530 题目：二叉树搜索树的最小绝对差
    给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
    示例：
        输入：
           1
            \
             3
            /
           2
    输出：
        1
    解释：
    最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。

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
    int minValue = INT_MAX;
    TreeNode *pre = nullptr;
    void inorder(TreeNode *root)
    {
        if(root == nullptr){
            return;
        }
        inorder(root->left);
        if(pre){
            minValue = min(minValue, root->val - pre->val);
        }

        pre = root;
        inorder(root->right);
    }
    void inorderNon(TreeNode *root)
    {
        if(root == nullptr){
            return;
        }
        stack<TreeNode*> st;
        TreeNode *pre = nullptr;
        while(!st.empty() || root){
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(pre){
                minValue = min(minValue, root->val - pre->val);
            }
            pre = root;
            root = root->right;

        }
    }

    int getMinimumDifference(TreeNode* root) {

        inorderNon(root);
        return minValue;
    }
};
int main(){

    system("pause");
    return 0;
}