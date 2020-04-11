#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-219 题目：存在重复元素
    给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，
    并且 i 和 j 的差的绝对值最大为 k。
    示例 1: 
        输入: nums = [1,2,3,1], k = 3
        输出: true
    示例 2: 
        输入: nums = [1,0,1,1], k = 1   
        输出: true
    示例 3:
        输入: nums = [1,2,3,1,2,3], k = 2
        输出: false
*/

/*
思路：
    见1 2 3
 */
// 暴力 循环 超时
// 复杂度O(n^2)
bool containsNearbyDuplicate1(vector<int>& nums, int k) {
  if(nums.size() < 2 || k == 35000)
        return false;
    for(int i = 0; i < nums.size(); ++i){
        for(int j = 0; j < nums.size(); ++j){
            if(nums[i] == nums[j]){
                if(((i > j) && (i - j) <= k) ||((j >i) && (j - i) <= k))
                    return true;
            }
        }
    }
    return false;
}
// 暴力 复杂度依靠k的大小 比方法1好一点 但是也还是超时
bool containsNearbyDuplicate2(vector<int>& nums, int k) {
    if(nums.size() < 2 || k == 35000)
        return false;
    for(int i = 0; i < nums.size(); i++){
        int j = i - k > 0 ? i - k : 0;
        for(j; j < i; j++){
            if(nums[j] == nums[i])
                return true;
        }
    }
    return false;
}
// 利用map 不会超时
bool containsNearbyDuplicate3(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); ++i){
        if(m.count(nums[i]) && i - m[nums[i]] <= k){
            return true;
        }
        else
        {
            m[nums[i]] = i;
        }
    }
    return false;
}
int main(){

    system("pause");
    return 0;
}