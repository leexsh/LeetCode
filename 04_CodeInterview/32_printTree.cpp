#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/7/9.
//
/*
 * 剑指 Offer 32 - I. 从上到下打印二叉树
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：
    [3,9,20,15,7]
 *
 * */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> res;
    vector<int> levelOrder(TreeNode* root) {
        if (!root) {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            TreeNode *node = dq.front();
            dq.pop_front();
            res.push_back(node->val);
            if (node->left){
                dq.push_back(node->left);

            }
            if (node->right) {
                dq.push_back(node->right);
            }
        }
        return res;
    }
};