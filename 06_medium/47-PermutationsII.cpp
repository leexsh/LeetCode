#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
47. 全排列 II
    给定一个可包含重复数字的序列，返回所有不重复的全排列。
    示例:
        输入: [1,1,2]
        输出:
            [
                [1,1,2],
                [1,2,1],
                [2,1,1]
            ]
*/

/*
思路：

 */
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, vector<bool> &used, vector<int> &path)
    {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || (i > 0 && nums[i-1] == nums[i] && used[i-1] == false)) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, used, path);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> path;
        dfs(nums, used, path);
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}