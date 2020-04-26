#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-81 题目：搜索旋转排序数组 II
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
    编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
    示例 1:
        输入: nums = [2,5,6,0,0,1,2], target = 0
        输出: true
    示例 2:
        输入: nums = [2,5,6,0,0,1,2], target = 3
        输出: false
    进阶:
*/

/*
思路：

 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};
int main(){
    vector<int> nums;
    int target = 0;
    find(nums.begin(), nums.end(),target);
    system("pause");
    return 0;
}