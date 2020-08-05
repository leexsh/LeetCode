#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-102 题目：二叉树的层次遍历
    给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
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
          [9,20],
          [15,7]
        ]
*/

/*
思路：

 */
class TreeNode{
public:
    TreeNode(int v) : val(v), left(nullptr),  right(nullptr){}    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> vec;
    if(root == nullptr){
        return vec;
    }        
    deque<TreeNode *> dq; // 双端队列
    dq.push_back(root);
    while(!dq.empty()){
        vector<int> nums;
        int num = dq.size();
        for(int i = 0; i < num; ++i){
            nums.push_back(dq.front()->val);
            if(dq.front()->left){
                dq.push_back(dq.front()->left);
            }
            if(dq.front()->right){
                dq.push_back(dq.front()->right);
            }
            dq.pop_front();
        }
        vec.push_back(nums);
        nums.resize(0);  
    }
    return vec;
}

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                root = dq.front();
                dq.pop_front();
                temp.push_back(root->val);
                if (root->left) {
                    dq.push_back(root->left);
                }
                if (root->right) {
                    dq.push_back(root->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}