#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-28 题目：剑指 Offer 28. 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3



示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true

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
    bool core_deal(TreeNode* p1, TreeNode* p2){
        if (p1 == nullptr && p2 == nullptr) {
            return true;
        }
        if (p1 == nullptr || p2 == nullptr) {
            return false;
        }

        if (p1->val != p2->val) {
            return false;
        }
           return core_deal(p1->left, p2->right) && core_deal(p1->right, p2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return core_deal(root, root);
    }
};
int main(){

    system("pause");
    return 0;
}