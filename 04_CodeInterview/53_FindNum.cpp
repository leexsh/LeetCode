#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
剑指 Offer 53 - II. 0～n-1中缺失的数字
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
*/

/*
思路：

 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int, int> ma;
        for (auto nu : nums) {
            ma[nu]++;
        }
        return ma[target] ? ma[target] : 0;
    }
};
int main(){

    system("pause");
    return 0;
}