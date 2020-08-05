#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-15 题目：三数之和
    给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
    注意：答案中不可以包含重复的三元组。
    例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
    满足要求的三元组集合为：
    [
        [-1, 0, 1],
        [-1, -1, 2]
    ]

*/

/*
思路：
    先排序 固定一个数 让两个指针移动
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vec;
    if(nums.size() < 3){
        return vec;
    }
    int size = nums.size() - 1;
    //先排序
    sort(nums.begin(), nums.end());
    for(int i = 0; i <= size; i++){
        // nums[i] 大于0 那么nums[i]后面的数都大于0 不存在三个数相加为0
        if(nums[i] > 0){
            break;
        }
        // 判断i是否重复 i重复 直接跳过
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        // 左下标 是i的下一个数
        int L = i + 1;
        // 右下标 是最后一个数
        int R = size;
        while(L < R){
            int sum = nums[i] + nums[L] + nums[R];
            if(sum == 0){
                // 等于0 添加到数组中
                vector<int> temp{nums[i], nums[R], nums[L]};
                vec.push_back(temp);
                //去掉跟nums[L]和nums[R]重复的元素
                while(L < R && nums[L+1] == nums[L]){L++;}
                while(L < R && nums[R] == nums[R - 1]){R--;}
                // 继续寻找跟nums[i]三数之和相加为0的两个数
                L++;
                R--;
            }
            else if(sum > 0){
                R--;
            }
            else if(sum < 0){
                L++;
            }
        }
    }
    return vec;
}

int main(){

    system("pause");
    return 0;
}