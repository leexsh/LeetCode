#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
/* 
LeetCode-189 题目：翻转数组
    给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。    
    示例 1:
        输入: [1,2,3,4,5,6,7] 和 k = 3
        输出: [5,6,7,1,2,3,4]
    解释:
        向右旋转 1 步: [7,1,2,3,4,5,6]
        向右旋转 2 步: [6,7,1,2,3,4,5]  
        向右旋转 3 步: [5,6,7,1,2,3,4]
    示例 2:
        输入: [-1,-100,3,99] 和 k = 2
        输出: [3,99,-1,-100]
    解释: 
        向右旋转 1 步: [99,-1,-100,3]
        向右旋转 2 步: [3,99,-1,-100]
    说明:
	    尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
	    要求使用空间复杂度为 O(1) 的 原地 算法。
*/

/*
思路：
    方法如下的
 */

// 方法一：
// 时间复杂度O(n) 空间复杂度O(n) 不符合题目要求 但是仍然可以作为一种参考的方法
// 思路：拷贝个个nums一样的数组 利用映射关系 i->(i + k) % num.size() 将数字放到对应的位置
 void rotate1(vector<int>& nums, int k) {
     vector<int> vec = nums;
     for(int i = 0; i < nums.size(); i++){
         nums[(i + k)% nums.size()] = vec[i];
     }
 }

// 方法二：
// 这个方法还是比较巧的 很难看出来
// 先把前k个元素翻转一下 再把后n-k个元素翻转一下
// 最后再把整个数组翻转一下
// 1 2 3 4 5 6 7 
// 4 3 2 1    5 6 7 
// 4 3 2 1    7 6 5
// 5 6 7 1 2 3 4
void rotate2(vector<int>& nums, int k) {
    if(nums.empty() || (k %=nums.size()) == 0){
        return;
    }
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}

// 方法三
// 不断的将第一个元素插入到数组最后
// 再把第一个元素去掉
void rotate3(vector<int>& nums, int k) {
    if(nums.empty() || (k %=nums.size()) == 0){
        return;
    }
    int n = nums.size();
    for(int i = 0; i < n - k; i++){
        nums.push_back(nums[0]);
        nums.erase(nums.begin());
    }
}

// 方法四
// 利用stl的插入方法 将后面n-k个元素 直接插入到容器头部 再重新截取容器大小
void rotate4(vector<int>& nums, int k) {
    if(nums.empty() || (k %=nums.size()) == 0){
        return;
    }
    int size = nums.size();
    nums.insert(nums.begin(), nums.end() - k, nums.end());
    nums.resize(size);
}

// 方法五 leetcode通不过 超时
// 就是循环的方法 逐个元素 从左向右移动
void rotate4(vector<int>& nums, int k) {
    k %= nums.size();
    for(int i = 0; i <k; i++){
        int x = nums[nums.size() - 1];
        for(int j = nums.size()-1; j > 0; j--){
            nums[j] = nums[j - 1];
        }
        nums[0] = x;
    }
}
int main(){

    system("pause");
    return 0;
}