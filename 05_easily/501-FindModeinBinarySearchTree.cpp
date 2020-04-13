#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-501 题目：二叉树搜索树中的众数
    给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
    假定 BST 有如下定义：
        结点左子树中所含结点的值小于等于当前结点的值
        结点右子树中所含结点的值大于等于当前结点的值
        左子树和右子树都是二叉搜索树
    例如：
    给定 BST [1,null,2,2],
       1
        \
         2
        /
       2
    返回[2].

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
    map<int,int> map;
    void inorder(TreeNode *root)
    {
        if(root == nullptr)
        {
            return;
        }
        inorder(root->left);
        if(root){
            map[root->val]++;
        }

        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root)
        {
            return vector<int>();
        }
        vector<int> vec;
        inorder(root);
        int count = 0;
        for(auto i : map)
        {
//            cout<<i.first<<" "<<i.second<<endl;
            if(i.second > count)
            {
                count = i.second;
            }
        }
//        cout<<count<<endl;
        for(auto i : map)
        {
            if(i.second == count)
            {
                vec.push_back(i.first);
            }
        }
        return vec;
    }
};
int main(){

    system("pause");
    return 0;
}