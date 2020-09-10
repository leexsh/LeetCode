#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-56 题目：区间合并
    给出一个区间的集合，请合并所有重叠的区间。
    示例 1:
        输入: [[1,3],[2,6],[8,10],[15,18]]
        输出: [[1,6],[8,10],[15,18]]
        解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
    示例 2:
        输入: [[1,4],[4,5]]
        输出: [[1,5]]
        解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

/*
思路：

 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size();) {
            int t = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t)
            {
                t = max(intervals[j][1], t);
                j++;
            }
            res.push_back({intervals[i][0], t});
            i = j;
        }
        return res;
    }
};

class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (res.empty() || res.back()[1] < L) {
                res.push_back({L, R});
            } else {
                res.back()[1] = max(R, res.back()[1]);
            }
        }
        return res;
    }
};
int main(){

    return 0;
}