#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/7/9.
//
/*
剑指 Offer 32 - III. 从上到下打印二叉树 III
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。



例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        int hang = 1;
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> vec;
            TreeNode *node;
            while (size > 0) {
                if (hang & 1) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left) {
                        dq.push_back(node->left);
                    }
                    if (node->right) {
                        dq.push_back(node->right);
                    }
                } else {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right) {
                        dq.push_front(node->right);
                    }
                    if (node->left) {
                        dq.push_front(node->left);
                    }
                }
                vec.push_back(node->val);
                size--;
            }
            res.push_back(vec);
            hang++;
        }
        return res;
    }
};