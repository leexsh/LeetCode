#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/8/4.
//

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr){}
};

class Solution {
public:
    vector<vector<int>> res;
    void dfs(TreeNode* root, vector<int> &path, int sum)
    {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {
            res.push_back(path);
        }
        dfs(root->left, path, sum - root->val);

        dfs(root->right, path, sum - root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) {
            return res;
        }
        vector<int> vec;
        dfs(root, vec, sum);
        return res;
    }
};
int main() {


    return 0;
}