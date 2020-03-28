#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-41 题目：缺失的第一个整数
    给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
    示例 1:
        输入: [1,2,0]
        输出: 3
    示例 2:
        输入: [3,4,-1,1]
        输出: 2
    示例 3:
        输入: [7,8,9,11,12]
        输出: 1
*/

/*
思路：

 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int max = 0;
        for(auto i : nums)
        {
            if(i > max){
                max = i;
            }
            s.insert(i);
        }

        for(int i = 1; i < max; i++){
            if(s.count(i) == 0){
                return i;
            }
        }
        return max + 1;
    }
};
int main(){

    system("pause");
    return 0;
}