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

 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vec;
    int i, j;
    int count = 0;
    for(i = 0;i<nums.size(); i++){
        for(j = 0; j < nums.size(); j++){
            for(int k = 0; k < nums.size(); k++){
                if(nums[i] + nums[j] + nums[k] == 0 && (i != j != k)){
                    vec[count].push_back(i);
                    vec[count].push_back(j);
                    vec[count].push_back(k);
                    count++;
                }
            }

        }
    }
    return vec;

}
int main(){

    system("pause");
    return 0;
}