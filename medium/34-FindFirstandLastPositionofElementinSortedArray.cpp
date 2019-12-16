#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-34 题目：在排序树组中查找给顶元素的第一个和最后一个位置
    给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
    你的算法时间复杂度必须是 O(log n) 级别。
    如果数组中不存在目标值，返回 [-1, -1]。
    示例 1:
        输入: nums = [5,7,7,8,8,10], target = 8
        输出: [3,4]
    示例 2:
        输入: nums = [5,7,7,8,8,10], target = 6 
        输出: [-1,-1]
*/

/*
思路：
    顺序遍历 复杂度O(N)
 */
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> vec(2, -1);
    int i, j;
    for(i = 0; i < nums.size(); i++){
        if(nums[i] == target){
            vec[0] = i;
            break;
        }
    }
    for(j = nums.size() - 1; j >= i; j--){
        if(nums[j] == target){
            vec[1] = j;
            break;
        }
    }
    return vec;
} 
// 二分查找 分别找到左右区间
// 二分找到最左边的数 
int find_left(vector<int>& nums, int target){
    if(nums.empty()) return -1;
    int left = 0;
    int right = nums.size();
    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            right = mid;
        }
        else if(nums[mid] > target){
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(nums.size() == left){
        return -1;
    }
    else
    return nums[left] == target ? left : -1;
}

// 二分 找到最右边的数
int find_right(vector<int>& nums, int target){
    if(nums.empty()){
        return -1;
    }
    int l = 0;
    int r = nums.size();
    while(l < r){
        int mid = l + (r - l) / 2;
        if(nums[mid] == target) l = mid + 1;
        else if(nums[mid] > target) r = mid;
        else
        {
            l = mid + 1;
        }
    }
    if(l == 0){
        return -1;
    }
    return nums[l - 1] == target ? l - 1 : -1; 
}
vector<int> searchRange1(vector<int>& nums, int target) {
    vector<int> vec;
    vec.push_back(find_left(nums,target));
    vec.push_back(find_right(nums, target));
    return vec;
}
vector<int> searchRange2(vector<int>& nums, int target) {
    // 返回一个指向第一个大于等于target的迭代器
    auto start = lower_bound(nums.begin(), nums.end(), target);
    // 返回一个指向第一个大于target的迭代器
    auto finish = upper_bound(nums.begin(), nums.end(), target);
    // 第一个大于等于target的指针和一个大于target的指针 相等 说明不存在
    if(start == finish){
        return {-1,-1};
    }
    // 返回 
    return {start - nums.begin(), finish - 1 - nums.begin()};
}


int main(){
    vector<int> vec{5,7,7,8,8,10};
    vector<int> v =  searchRange2(vec, 8);
    for(auto i : v){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}