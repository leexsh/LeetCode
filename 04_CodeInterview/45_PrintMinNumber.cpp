#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
//
// Created by leexsh on 2020/7/12.
//

/*
 * 剑指 Offer 45. 把数组排成最小的数
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
 * */
bool compare(int a, int b)
{
    string aa, bb;
    aa += to_string(a);
    aa += to_string(b);
    bb += to_string(b);
    bb += to_string(a);
    return aa < bb;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string res;
        for (int ch : nums) {
            res += to_string(ch);
        }
        return res;
    }

};
int main() {


    return 0;
}