#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/3/30.
//
/*
 LeetCode-108 题目：将数组转为二叉搜索树

    将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
    示例:
        给定有序数组: [-10,-3,0,5,9],
        一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
         0
        / \
      -3   9
      /   /
    -10  5
 */

/*
思路：

 */
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

// 跟利用中序遍历和前序遍历构造是一样的
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return nullptr;
        }

        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> leftArr, rightArr;
        for(int i = 0; i < mid; i++){
            leftArr.push_back(nums[i]);
        }
        for(int i = mid + 1; i < nums.size(); i++){
            rightArr.push_back(nums[i]);
        }
        root->left = sortedArrayToBST(leftArr);
        root->right = sortedArrayToBST(rightArr);
        return root;
    }
};


int main() {


    return 0;
}