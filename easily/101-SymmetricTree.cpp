#include <iostream>
#include <stack>
//#include
#include <deque>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// DFS
class Solution {
public:
    bool dfs(TreeNode *r1, TreeNode *r2)
    {
        if(r1 == nullptr && r2 == nullptr){
            return true;
        }
        if(r1 == nullptr || r2 == nullptr){
            return false;
        }
        if(r1->val != r2->val){
            return false;
        }
        return r1->val == r2->val && dfs(r1->left, r2->right) && dfs(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root,root);
    }
};

// 队列
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        deque<TreeNode*> que;
        que.push_back(root->left);
        que.push_back(root->right);
        while(!que.empty()){
            TreeNode *p1 = que.front();
//            TreeNode *p1 = que.
            que.pop_front();
            TreeNode *p2 = que.front();
            que.pop_front();
            if(p1 == nullptr && p2 == nullptr){
                continue;
            }
            if(p1== nullptr || p2 == nullptr){
                return false;
            }

            if(p1->val != p2->val){
                return false;
            }
            que.push_back(p1->left);
            que.push_back(p2->right);
            que.push_back(p1->right);
            que.push_back(p2->left);
        }
        return true;
    }
};
int main() {

    cout<<endl;

    return 0;
}