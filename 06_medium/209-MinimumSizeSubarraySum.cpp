#include "bits/stdc++.h"
using namespace std;
/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。



示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/

/*
思路：

 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int res = INT_MAX;
        int sum = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum >= s) {
                res = min(res, j- i + 1);
                sum -= nums[i++];;
            }
            j++;
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main(){

    system("pause");
    return 0;
}