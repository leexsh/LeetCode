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


int main(){

    system("pause");
    return 0;
}