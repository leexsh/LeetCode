#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-45 题目：跳跃游戏II
    给定一个非负整数数组，你最初位于数组的第一个位置。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    你的目标是使用最少的跳跃次数到达数组的最后一个位置。
    示例:
        输入: [2,3,1,1,4]
        输出: 2
    解释: 跳到最后一个位置的最小跳跃数是 2。
        从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
    说明:
        假设你总是可以到达数组的最后一个位置
*/

/*
思路：

 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int maxDis = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            maxDis = max(maxDis, i+nums[i]);
            if(i == end)
            {
                end = maxDis;
                ans++;
            }
        }
        return ans;
    }
};
int main(){

    system("pause");
    return 0;
}