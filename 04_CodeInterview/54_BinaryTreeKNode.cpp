#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-34 题目：二叉树中K大的节点
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// 中序遍历 先left后right是从小到大
// 先right后left是从大到小

// 优先队列 +  中序遍历 先找right 速度更快 递归
class Solution {
public:

    void inorder(TreeNode *node,priority_queue<int,vector<int>,greater<int>> &que,int k)
    {
        if(node == nullptr){
            return;
        }
        inorder(node->right, que, k);
        if(que.size() < k)
        {
            que.push(node->val);
        } else{
            if(node->val > que.top()){
                que.pop();
                que.push(node->val);
            }
        }
        inorder(node->left, que,k);
    }
    int kthLargest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>> que;
        inorder(root,que,k);
        return que.top();
    }
};

/// 不用堆 digui
class Solution1 {
public:
    int n = 0;
    void inorder(TreeNode *node,int k, int &res)
    {
        if(node == nullptr){
            return;
        }
        inorder(node->right, k,res);
        n++;
        if(n == k){
            res = node->val;
            return;
        }
        inorder(node->left, k,res);
    }
    int kthLargest(TreeNode* root, int k) {
        int res;
        inorder(root,k,res);
        return res;
    }
};

// 非递归
class Solution2 {
public:
    vector<int> vec;
    void inorderRec(TreeNode *node)
    {
        if(node == nullptr){
            return;
        }
        inorderRec(node->right);
        vec.push_back(node->val);
        inorderRec(node->left);
    }
    void inorderNonRec(TreeNode *node)
    {
        if(node == nullptr){
            return;
        }
        stack<TreeNode*> st;
        while(!st.empty() || node)
        {
            while (node)
            {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            vec.push_back(node->val);
            node = node->right;
        }
    }
    int kthLargest(TreeNode* root, int k) {
        int res;
        inorderRec(root);
        return vec[k-1];
    }
};
int main(){

    system("pause");
    return 0;
}