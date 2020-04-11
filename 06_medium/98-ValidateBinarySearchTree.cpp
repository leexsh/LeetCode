#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-98 题目：搜索二叉树
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。
    假设一个二叉搜索树具有如下特征：
    	节点的左子树只包含小于当前节点的数。
	    节点的右子树只包含大于当前节点的数。
	    所有左子树和右子树自身必须也是二叉搜索树。
    示例 1:
        输入:
            2
           / \
          1   3
        输出: true
    示例 2:
        输入:
            5
           / \
          1   4
           / \
          3   6
        输出: false
    解释: 输入为: [5,1,4,null,null,3,6]。
         根节点的值为 5 ，但是其右子节点值为 4 。
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
// 递归
bool isOK(TreeNode *node,  long leftVal, long rightVal){
    if(node == nullptr){
        return true;
    }
    else if(leftVal >= node->val || rightVal <= node->val){
        return false;
    }
    return isOK(node->left, leftVal,node->val) && isOK(node->right, node->val,rightVal);
}
bool isValidBST(TreeNode* root) {
    return isOK(root,LONG_MIN,LONG_MAX);
}

// 非递归 利用中序遍历
bool isValidBST1(TreeNode *root){
    long num = LONG_MIN;
    stack<TreeNode*> s;
    while(!s.empty() || root != nullptr){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if(root->val <= num){
            return false;
        }
        num = root->val;
        root = root->right;
    }
    return true;
}
int main(){
    TreeNode *p = new TreeNode(5);
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p->right->left = new TreeNode(3);
    p->right->right = new TreeNode(6);
    isValidBST1(p);
    system("pause");
    return 0;
}