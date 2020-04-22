#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-199 题目：岛屿的数量
    给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
    示例:
        输入: [1,2,3,null,5,null,4]
        输出: [1, 3, 4]
    解释:
       1            <---
     /   \
    2     3         <---
    \     \
     5     4       <---


*/

/*
思路：
    层次遍历
 */
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
int main(){

    system("pause");
    return 0;
}