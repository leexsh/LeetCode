#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-300 题目：最长上升子序列
    给定一个无序的整数数组，找到其中最长上升子序列的长度。
    示例:
        输入: [10,9,2,5,3,7,101,18]
        输出: 4 
    解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
    说明:
    	可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
	    你算法的时间复杂度应该为 O(n2) 。

*/

/*
思路：

 */
// 动态规划 无优化
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        int maxlen = 1;
        vector<int> vec(nums.size());
        // vec[0] = 1;
        for(int i = 0; i< nums.size(); i++){
            vec[i] = 1;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] < nums[i])
                {
                    vec[i] = max(vec[j]+ 1, vec[i]);
                }
            }
            maxlen = max(vec[i], maxlen);
        }
        return maxlen;
    }
};

// 利用二分优化
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        int len = 1;
        vector<int> vec(nums.size() + 1, 0);
        vec[1] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > vec[len]){vec[++len] = nums[i];}
            else
            {
                int l = 1, r = len, pos = 0;
                while(l <= r){
                    int mid = l + (r - l) / 2;
                    if(vec[mid] < nums[i])
                    {
                        // pos = mid;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                vec[l] = nums[i];
            }
        }
        return len;
    }
};
int main(){
    // INT_MAX
    // string s;
    // reverse
    system("pause");
    return 0;
}