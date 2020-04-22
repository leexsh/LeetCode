#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-39 题目：组合总和
    给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
    candidates 中的数字可以无限制重复被选取。
    说明：
        所有数字（包括 target）都是正整数。
        解集不能包含重复的组合。
    示例 1:
        输入: candidates = [2,3,6,7], target = 7,
        所求解集为:
        [
            [7],
            [2,2,3]
        ]
    示例 2:
        输入: candidates = [2,3,5], target = 8,
        所求解集为:
        [
            [2,2,2,2],
            [2,3,3],
            [3,5]
        ]
*/

/*
思路：
 */

// 回溯 做减法
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()){
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dfs(candidates,target,0,vec);

        return res;
    }

    /*
     * candidate:搜索数组
     * target:目标值
     * startPos:搜索起点
     * path:添加路径
     * */
    void dfs(vector<int> &candidate,int target, int startPos,vector<int> &path)
    {
        if(target == 0)
        {
            res.push_back(path);
            return;
        }

        for(int i = startPos; i < candidate.size(); i++)
        {
            if(target - candidate[i] < 0)
            {
                break;
            }

            path.push_back(candidate[i]);
            dfs(candidate, target - candidate[i], i,path);
            path.pop_back();
        }
    }
};

// 回溯 做加法
class Solution1 {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()){
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dfs(candidates,target,0,0,vec);
        return res;
    }
    void dfs(vector<int> candidates, int target, int current,int startPos, vector<int> &path)
    {
        if(target == current)
        {
            res.push_back(path);
            return;
        }
        for (int i = startPos; i < candidates.size(); ++i) {
            if(current > target)
            {
                break;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target,current+candidates[i], i,path);
            path.pop_back();
        }
    }

};

int main(){
    return 0;
}