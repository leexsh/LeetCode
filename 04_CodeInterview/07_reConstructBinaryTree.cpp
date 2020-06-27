#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-07 题目：重建二叉树
    输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    例如，给出
        前序遍历 preorder = [3,9,20,15,7]
        中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：
        3
       / \
      9  20
     /  \
    15   7
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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
        {
            return nullptr;
        }
        int value = preorder[0];
        TreeNode *root = new TreeNode(value);
        vector<int> preleft, preright, inleft,inright;
        int gen = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == value){
                gen = i;
                break;
            }
        }
        for(int i = 0; i < gen; i++){
            preleft.push_back(preorder[i+1]);
            inleft.push_back(inorder[i]);
        }
        for (int j = gen+1; j < preorder.size(); ++j) {
            preright.push_back(preorder[j]);
            inright.push_back(inorder[j]);
        }
        root->left = buildTree(preleft,inleft);
        root->right = buildTree(inleft,inright);
        return root;
    }
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
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        int value = preorder[0];
        TreeNode *root = new TreeNode(value);

        vector<int> preLeft, inLeft, preRight, inRight;
        int gen = 0;
        int i;
        for(i = 0; i < inorder.size(); i++){
            if (inorder[i] == value) {
                gen = i;
                break;
            }
        }

        for (i = 0; i < gen; ++i) {
            preLeft.push_back(preorder[i+1]);
            inLeft.push_back(inorder[i]);
        }

        for (i = gen + 1; i < preorder.size(); ++i) {
            preRight.push_back(preorder[i]);
            inRight.push_back(inorder[i]);
        }

        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);

        return root;

    }
};
