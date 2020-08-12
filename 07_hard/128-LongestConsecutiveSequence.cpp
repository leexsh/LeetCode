#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
    给定一个未排序的整数数组，找出最长连续序列的长度。
    要求算法的时间复杂度为 O(n)。
    示例:
        输入: [100, 4, 200, 1, 3, 2]
        输出: 4
    解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/
/*
思路：

 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 0;
        unordered_set<int> ust(nums.begin(), nums.end());
        for (auto i : nums) {
            if (ust.count(i - 1)) { continue;}
            int cnt = 1;
            while (ust.count(++i)) {
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }

};
int main(){

    system("pause");
    return 0;
}