#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-46 题目：全排列
    给定一个 没有重复 数字的序列，返回其所有可能的全排列。
    示例:
        输入: [1,2,3]
        输出:
            [
                [1,2,3],
                [1,3,2],
                [2,1,3],
                [2,3,1],
                [3,1,2],
                [3,2,1]
            ]
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            return res;
        }
        vector<int> vec;
        dfs(nums, vec);
        return res;
    }
    void dfs(vector<int> &nums, vector<int> &vec)
    {
        if(vec.size() == nums.size())
        {
            res.push_back(vec);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(find(vec.begin(), vec.end(), nums[i]) == vec.end())
            {
                vec.push_back(nums[i]);
                dfs(nums,vec);
                vec.pop_back();
            }
        }
    }
};
int main(){

    system("pause");
    return 0;
}