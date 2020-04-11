#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-106 题目：从中序与后序遍历序列构造二叉树
    根据一棵树的中序遍历与后序遍历构造二叉树。  
    注意:
        你可以假设树中没有重复的元素。
    例如，给出
        中序遍历 inorder = [9,3,15,20,7]
        后序遍历 postorder = [9,15,7,20,3]
    返回如下的二叉树：
        3
       / \
      9  20
      /  \
     15   7
*/

/*
思路：
    递归 类似于通过中序和先序构造
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // kong
    if(inorder.empty() || postorder.empty()){
        return nullptr;
    }
    // 先根据后序的最后一个节点 构造根节点
    int rootValue = postorder[postorder.size() - 1];
    TreeNode *root = new TreeNode(rootValue);
    vector<int> leftIn, rightIn, leftPost, rightPost;
    // 在中序中找到根节点
    int gen = 0;
    for(int i = 0; i < inorder.size(); i++){
        if(inorder[i] == rootValue){
            gen = i;
            break;
        }
    }
    // 把左子树的值全都放进中序和后序遍历中
    for(int i = 0; i < gen; i++){
        leftIn.push_back(inorder[i]);
        leftPost.push_back(postorder[i]);
    }
    // 将右子树放入
    for(int i = gen + 1; i < inorder.size(); i++){
        rightIn.push_back(inorder[i]);
        rightPost.push_back(postorder[i - 1]);
    }
    // 递归构造
    root->left = buildTree(leftIn, leftPost);
    root->right = buildTree(rightIn, rightPost);
    return root;
}
int main(){

    system("pause");
    return 0;
}