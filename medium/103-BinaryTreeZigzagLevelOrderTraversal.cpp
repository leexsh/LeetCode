#include <iostream>
#include <stack>
#include <vector>
#include <queue>
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
        queue<TreeNode *> st;
        vector<vector<int>> vec;
        st.push(root);
        int level = 0;
        while(!st.empty())
        {
            int size = st.size();
//            用deque可以提高速度 不然也可以用vector
            deque<int> temp;
            while(size--)
            {
                TreeNode *p = st.front();
                st.pop();
                if(level % 2 == 0){
                    temp.push_back(p->val);
                } else{
                    temp.push_front(p->val);
                }
                if(p->left){
                    st.push(p->left);
                }
                if(p->right){
                    st.push(p->right);
                }

            }
            level++;
            vec.push_back(vector<int>(temp.begin(), temp.end()));
        }
        return vec;
    }
};

int main() {

    cout<<endl;

    return 0;
}