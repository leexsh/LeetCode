#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-40 题目：组合总和II
    给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
    candidates 中的每个数字在每个组合中只能使用一次。
    说明：
        所有数字（包括目标数）都是正整数。
        解集不能包含重复的组合。 
    示例 1:
        输入: candidates = [10,1,2,7,6,1,5], target = 8,
        所求解集为:
        [
            [1, 7],
            [1, 2, 5],
            [2, 6],
            [1, 1, 6]
        ]
    示例 2:
        输入: candidates = [2,5,2,1,2], target = 5,
        所求解集为:
        [
            [1,2,2],
            [5]
        ]

*/

/*
思路：
 */

// 回溯 做减法
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        if (candidates.empty()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dfs(candidates, target, 0, vec);
        return res;
    }

    void dfs(vector<int> &candidates, int target,int startPos, vector<int> &path)
    {
        if(target == 0)
        {
            res.push_back(path);

            return;
        }
        for (int i = startPos; i < candidates.size(); ++i) {
            if(candidates[i] > target){
                return;
            }
            if(target - candidates[i] < 0)
            {
                break;
            }
            if(i > startPos && candidates[i] == candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i+1,path);
            path.pop_back();
        }
    }
};


int main(){
    return 0;
}