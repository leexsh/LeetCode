#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-33 题目：搜索旋转排序数组
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
    搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
    你可以假设数组中不存在重复的元素。
    你的算法时间复杂度必须是 O(log n) 级别。
    示例 1:
        输入: nums = [4,5,6,7,0,1,2], target = 0
        输出: 4
    示例 2:
        输入: nums = [4,5,6,7,0,1,2], target = 3
        输出: -1
*/

/*
思路：
    分别在两个区间上二分
 */

int search(vector<int>& nums, int target) {
    if(nums.size() < 1)
        return -1;
    int i;
    // 找到区间划分点
    for(i = 1;i<nums.size(); i++){
        if(nums[i-1] > nums[i]){
            break;
        }
    }   
    // cout<<"i = "<<i<<endl;
    // int mid;     
    // 左边区间二分
    int low = 0;
    int high = i - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            // return mid +i;
            return mid;
        }
        else if(nums[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    // 右边区间二分
    low = i;
    high = nums.size() - 1;
    while(low <= high){
        
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            // return mid - i;
            return mid;
        }
        else if(nums[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int main(){
    vector<int> vec{4,5,6,7,0,1,2};
    int x = search(vec, 4);
    cout<<"location :"<< x<<endl;
    system("pause");
    return 0;
}