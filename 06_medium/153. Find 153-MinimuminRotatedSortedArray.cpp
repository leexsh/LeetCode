#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-153 题目：寻找旋转排序数组中的最小值
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
    请找出其中最小的元素。
    你可以假设数组中不存在重复元素。
    示例 1:
        输入: [3,4,5,1,2]
        输出: 1
    示例 2:
        输入: [4,5,6,7,0,1,2]
        输出: 0
*/

/*
思路：

 */
int findMin1(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    int left = 0;
    int mid = left;
    int right = nums.size() - 1;
    while(nums[left] > nums[right]){
        if(right - left == 1){
            mid = right;
            break;
        }
        int mid = left + (right - left) / 2;
        if(nums[mid] >= nums[left]){
                left = mid;
            }
            else if(nums[mid] <= nums[right]){
                right = mid;
        } 
    }
    return nums[mid];
}

// 2 1
int findMin1(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    int left = 0;
    int right = nums.size() - 1;
    while(nums[left] > nums[right]){
        int mid = left + (right - left) / 2;
        if(nums[mid] >= nums[left]){left = mid + 1;}
        else if(nums[mid] <= nums[right]){
            right = mid;
        }
    }
    return nums[left];
}
int main(){

    system("pause");
    return 0;
}