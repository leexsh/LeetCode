#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
        {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 0;
        while (!dq.empty())
        {
            int size = dq.size();
            deque<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = dq.front();
                dq.pop_front();
                if(level % 2 == 0){
                    temp.push_back(node->val);
                } else{
                    temp.push_front(node->val);
                }
                if(node->left){
                    dq.push_back(node->left);
                }
                if(node->right){
                    dq.push_back(node->right);
                }
            }
            level++;
            res.push_back(vector<int>(temp.begin(), temp.end()));
        }
        return res;
    }

};
int main() {

    cout<<endl;

    return 0;
}