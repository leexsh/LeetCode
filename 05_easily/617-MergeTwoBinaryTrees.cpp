#include "bits/stdc++.h"
using namespace std;
/*
617. 合并二叉树
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
输出:
合并后的树:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7
*/

/*
思路：

 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

// 迭代
class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        deque<TreeNode*> d1;
        d1.push_back(t1);
        d1.push_back(t2);
        while (!d1.empty()) {
            TreeNode* n1 = d1.front();
            d1.pop_front();
            TreeNode* n2 = d1.front();
            d1.pop_front();
            n1->val += n2->val;
            if (n1->left && n2->left) {
                d1.push_back(n1->left);
                d1.push_back(n2->left);
            }
            if (n1->right && n2->right) {
                d1.push_back(n1->right);
                d1.push_back(n2->right);
            }
            if (!n1->left && n2->left) {
                n1->left = n2->left;
            }
            if (!n1->right && n2->right) {
                n1->right = n2->right;
            }
        }
        return t1;
    }
};
int main(){

    system("pause");
    return 0;
}