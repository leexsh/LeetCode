#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-152 题目：乘积最大的子数组
    给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。
    示例 1:
        输入: [2,3,-2,4]
        输出: 6
        解释: 子数组 [2,3] 有最大乘积 6。
    示例 2:
        输入: [-2,0,-1]
        输出: 0
        解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

*/

/*
思路：

 */

// 超时
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int res = 1;
                res *= nums[j];

                max1 = max(res, max1);
            }
        }
        return max1;
    }
};
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = nums[0];
        int imax = nums[0];
        int imin = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] < 0)
            {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            max1 = max(imax, max1);
        }
        return max1;
    }
};

int main(){

    system("pause");
    return 0;
}