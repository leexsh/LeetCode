#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-198 题目：打家劫舍
    你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
    给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
    示例 1:
        输入: [1,2,3,1]
        输出: 4
        解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
        偷窃到的最高金额 = 1 + 3 = 4 。
    示例 2:
        输入: [2,7,9,3,1]
        输出: 12
        解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
        偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/

/*
思路：

 */
// 空间复杂度n
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        vector<int> vec(nums.size(), 0);
        vec[0] = nums[0];
        vec[1] = max(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); i++){
            vec[i] = max(vec[i-1], vec[i-2] + nums[i]);
        }
        return vec[nums.size() - 1];
    }
};

// 空间复杂度1
class Solution1 {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }

        int a = 0, b = 0;
        for(int i = 0; i < nums.size(); i++){
            int c = max(b, a+ nums[i]);
            a = b;
            b = c;
        }
        return b;
    }
};
int main(){

    system("pause");
    return 0;
}