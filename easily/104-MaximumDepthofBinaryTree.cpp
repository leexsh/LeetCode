#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-104 题目：二叉树的最大深度
    给定一个二叉树，找出其最大深度。
    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
    说明: 叶子节点是指没有子节点的节点。
    示例：
        给定二叉树 [3,9,20,null,null,15,7]，
            3
           / \
          9  20
          /  \
         15   7

        返回它的最大深度 3 。
*/

//  * Definition for a binary tree node.
// 递归
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 二叉树的深度遍历
int maxDepth(TreeNode* root) {
    if(root == NULL){return 0;}
    stack<pair<TreeNode*, int>> s;
    int deep = 0;//当前深度
    int maxDeep = 0;// 最大深度
    while(!s.empty() || root){
        // 一直压栈 压到最左
        while(root){
            s.push(make_pair(root, ++deep));
            root = root->left;
        }
        // 弹出
        root = s.top().first;
        deep = s.top().second;
        // 求出当前的最大深度
        if(maxDeep < deep){
            maxDeep = deep;
        }
        s.pop();
        // 再往右走
        root = root->right;
    }
    
    return maxDeep;
}
// 二叉树的广度遍历
int maxDeep(TreeNode *root){
    if(root == NULL) return 0;
    deque<TreeNode*> q;// 双端队列
    q.push_back(root);// 压头结点
    int deep = 0;
    while(!q.empty()){
        deep++;//深度
        int num = q.size();
        for(int i = 0; i < num; ++i){
            // 把同一层的下一层全部压入
            if(q.front()->left){
                q.push_back(q.front()->left);
            }
            if(q.front()->right){
                q.push_back(q.front()->right);
            }
            q.pop_front();
        }
    }
    return deep;
}
/*
思路：
    
 */
 int maxDepth(TreeNode* root) {
     if(root == NULL){
         return 0;
     }
     return max(maxDepth(root->left), maxDepth(root->right)) + 1;
 }

int main(){

    system("pause");
    return 0;
}