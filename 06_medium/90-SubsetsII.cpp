#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-90 题目：子集II
    给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
    说明：解集不能包含重复的子集。
    示例:
        输入: [1,2,2]
        输出:
            [
                [2],
                [1],
                [1,2,2],
                [2,2],
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.empty()){
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums,path,0);
        return res;
    }
    void dfs(vector<int> &nums, vector<int> &path, int begin)
    {

        res.push_back(path);
        for (int i = begin; i < nums.size(); ++i) {
            if(i > begin && nums[i-1] == nums[i]){
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, path, i+1);
            path.pop_back();
        }
    }
};

int main(){
    vector<int> nums;
    int target = 0;
    find(nums.begin(), nums.end(),target);
    system("pause");
    return 0;
}