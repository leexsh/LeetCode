#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-78 题目：子集
    给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
    说明：解集不能包含重复的子集。
    示例:
        输入: nums = [1,2,3]
    输出:
    [
        [3],
        [1],
        [2],
        [1,2,3],
        [1,3],
        [2,3],
        [1,2],
        []
    ]

*/

/*
思路：

 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()){
            return res;
        }
        vector<int> path;
        dfs(nums, path,0);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &path,int begin)
    {
        if(path.size() <= nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            dfs(nums,path,i+1);
            path.pop_back();
        }
    }
};
int main(){

    system("pause");
    return 0;
}