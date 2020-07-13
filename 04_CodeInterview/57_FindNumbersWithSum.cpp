#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：

*/

/*
思路：

 */
class Solution {
public:
    vector<int> res;
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty()) {
            return res;
        }
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                break;
            }else if (nums[i] + nums[j] < target) {
                i++;
            } else{
                j--;
            }
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}