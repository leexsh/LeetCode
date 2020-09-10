#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \
      4   5
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
/*
思路：

 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int res = INT_MIN;
    int get(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        int left = get(root->left);
        int right = get(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        get(root);
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}