#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-334 题目：
    给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
    数学表达式如下:
        如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
        使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
    说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。
    示例 1:
        输入: [1,2,3,4,5]
        输出: true
    示例 2:
        输入: [5,4,3,2,1]
        输出: false

*/

/*
思路：

 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> vec(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    vec[i] = max(vec[j] + 1, vec[i]);
                }
                if(vec[i] > 3){
                    return true;
                }
            }
        }
        return  false;
    }
};


// 维护两个数 找 最大的数
class Solution1 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX;
        int mid = INT_MAX;
        for (auto i : nums) {
            if(i <= small)
            {
                small = i;
            } else if(i <= mid){
                mid = i;
            } else{
                return true;
            }
        }
        return false;
    }
};

int main(){

    system("pause");
    return 0;
}