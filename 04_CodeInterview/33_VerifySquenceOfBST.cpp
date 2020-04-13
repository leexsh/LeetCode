#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-33 题目：二叉搜索树的后续遍历
    输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
    如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
    参考以下这颗二叉搜索树：
        5
       / \
      2   6
     / \
    1   3
    示例 1：
        输入: [1,6,3,2,5]
        输出: false
    示例 2：
        输入: [1,3,2,6,5]
        输出: true
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

// 递归
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()){
            return true;
        }
        int value = postorder[postorder.size() - 1];
        vector<int> leftVec, rightVec;
        int i = 0;
        for (i; i < postorder.size() - 1; ++i) {
            if(postorder[i] > value){
                break;
            }
            leftVec.push_back(postorder[i]);
        }
        int j = i;
        for (j; j < postorder.size() - 1; ++j) {
            if(postorder[j] < value){
                return false;
            }
            rightVec.push_back(postorder[j]);
        }
        bool leftFlag = true;
        if(i > 0){
            leftFlag = verifyPostorder(leftVec);
        }
        bool rightFlag = true;
        if(j < postorder.size()-1){
            rightFlag = verifyPostorder(rightVec);
        }
        return leftFlag && rightFlag;
    }
};
int main(){

    system("pause");
    return 0;
}