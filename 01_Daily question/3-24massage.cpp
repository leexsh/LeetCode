#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-3-24 题目：按摩师(同198)
       一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
    在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
    给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
    注意：本题相对原题稍作改动
    示例 1：
        输入： [1,2,3,1]
        输出： 4
        解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。   
    示例 2：
        输入： [2,7,9,3,1]
        输出： 12
        解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
    示例 3：
        输入： [2,1,4,5,3,1,1,3]
        输出： 12
        解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
*/

/*
思路：

 */

class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> vec(nums.size(),0);
        vec[0] = nums[0];
        vec[1] = max(nums[1], nums[0]);
        for(int i = 2; i < nums.size(); i++)
        {
            vec[i] = max(vec[i - 1], vec[i-2] + nums[i]);
        }
        return nums[nums.size() - 1];
    }
};
int main(){
    vector<int> v={1,2,3,1};
    Solution s;
    int x = s.massage(v);
//    system("pause");
    return 0;
}