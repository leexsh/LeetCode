#include <iostream>
#include <stack>
#include <vector>
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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
        {
            return vector<vector<int>>();
        }
        stack<TreeNode *> st;
        vector<vector<int>> vec;
        st.push(root);
        que
        while(!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
        }
    }
};

int main() {

    cout<<endl;

    return 0;
}