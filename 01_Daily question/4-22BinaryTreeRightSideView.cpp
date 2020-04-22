#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/4/22.
//

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr)
    {

    }
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
        {
            return res;
        }
        deque<TreeNode*> deq;
        deq.push_back(root);
        while(!deq.empty())
        {
            int size = deq.size();
            for (int i = 0; i < size; ++i) {
                root = deq.front();
                deq.pop_front();
                if(i == size - 1){
                    res.push_back(root->val);
                }
                if(root->left)
                {
                    deq.push_back(root->left);
                }
                if(root->right)
                {
                    deq.push_back(root->right);
                }
            }
        }
        return res;
    }
};
int main() {


    return 0;
}