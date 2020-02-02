#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-105 题目：从前序与中序遍历序列构造二叉树
    根据一棵树的前序遍历与中序遍历构造二叉树。
    注意:
        你可以假设树中没有重复的元素。
    例如，给出
        前序遍历 preorder = [3,9,20,15,7]   
        中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：
        3
       / \
      9  20
      /  \
     15   7
*/

/*
思路：
    递归构建
 */
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // 递归的终止条件
    if(preorder.empty() || inorder.empty()){
        return nullptr;
    }
    // 构造根节点
    int rootValue = preorder[0];
    TreeNode *root = new TreeNode(rootValue);
    int gen = 0;
    // 在中序遍历中找到根节点
    for(int i = 0; i < inorder.size(); i++){
        if(inorder[i] == rootValue){
            gen = i;
            break;
        }
    }

    // 根节点的左右子树
    vector<int> preLeft, preRight, inLeft, inRight;
    // 确定左子树的集合
    for(int i = 0; i < gen; i++){
        preLeft.push_back(preorder[i+1]);
        inLeft.push_back(inorder[i]);
    }
    // 确定右子树的集合
    for(int i = gen + 1; i < inorder.size(); i++){
        preRight.push_back(preorder[i]);
        inRight.push_back(inorder[i]);
    }
    root->left = buildTree(preLeft, inLeft);
    root->right = buildTree(preRight, inRight);
    return root;
}
int main(){

    system("pause");
    return 0;
}