#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-53 题目：最大子序列和

*/

/*
思路：
    给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
    示例:
        输入: [-2,1,-3,4,-1,2,1,-5,4],
        输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 */


class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxV = INT_MIN;
        for (int i = 0; i <nums.size() ; ++i) {
            int res = 0;
            for(int j = i; j < nums.size(); ++j)
            {
//                int res = 0;
                res += nums[j];
                maxV = max(res, maxV);
            }
        }
        return maxV;
    }
};

//dp
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0];
        int maxV = dp;
        for (int i = 1; i < nums.size(); ++i) {
            dp = max(dp + nums[i], nums[i]);
            maxV = max(dp, maxV);

        }
        return maxV;
    }
};


int main(){

    system("pause");
    return 0;
}