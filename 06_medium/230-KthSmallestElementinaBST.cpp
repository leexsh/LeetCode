#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-230 题目：二叉搜索树中第k小的元素
    给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
    说明：
        你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
    示例 1:
        输入: root = [3,1,4,null,2], k = 1
        3
       / \
      1   4
      \
       2
        输出: 1
    示例 2:
        输入: root = [5,3,6,2,4,null,null,1], k = 3
        5
       / \
      3   6
     / \
    2   4
   /
  1
        输出: 3

*/

/*
思路：
    递归
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
    void inorder(TreeNode *node, vector<int> &nums)
    {
        if(node == nullptr)
        {
            return ;
        }
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        if(k < 0 || root == nullptr){
            return -1;
        }
        inorder(root, vec);
        return vec[k-1];
    }
};
int main(){

    system("pause");
    return 0;
}