#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-16 题目：最接近的三数之和
    给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
    找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
    例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
    与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

*/

/*
思路：
    先排序，然后双指针
 */
int threeSumClosest(vector<int>& nums, int target){
    // 先确定一个res
    int res = nums[0] + nums[1] + nums[2];
    // 对数组进行排序
    sort(nums.begin(), nums.end());
    int size = nums.size() - 1;
    // 确定一个数 其他两个数进行双指针
    for(int i = 0; i <= size-2; i++){
        int L = i + 1;
        int R = size;
        while(L < R){
            // 三个数的之和
            int sum = nums[i]+nums[L]+nums[R];
            // 判断之前的差值与现在三个数与target的差值 取更小的一个
            if(abs(sum - target) < abs(res-target)){
                res = sum;
            } 
            // 如果差值等于0的话 最小了 直接返回
            if(abs(sum - target) == 0){
                return sum;
            }
            // 小的话 ++ 
            else if(target - sum > 0){
                L++;
            }
            // 大的话 --
            else if(target - sum < 0){
                R--;
            }
        }
    }        
    return res;
}
int main(){

    system("pause");
    return 0;
}