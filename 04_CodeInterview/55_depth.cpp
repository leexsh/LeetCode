#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：

*/

/*
思路：
剑指 Offer 55 - I. 二叉树的深度
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 */
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        deque<TreeNode *> dq;
        int depth = 0;
        dq.push_back(root);
        while (!dq.empty())
        {
            int size = dq.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = dq.front();
                dq.pop_front();
                if (node->left) {
                    dq.push_back(node->left);
                }
                if (node->right) {
                    dq.push_back(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};

int main(){

    system("pause");
    return 0;
}