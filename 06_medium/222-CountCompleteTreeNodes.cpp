#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-22 题目：二叉树中节点个数

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




// 中序遍历 先left后right是从小到大
// 先right后left是从大到小

// 优先队列 +  中序遍历 先找right 速度更快 递归
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
int main(){

    system("pause");
    return 0;
}