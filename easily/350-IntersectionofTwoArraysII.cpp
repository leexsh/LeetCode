#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-350 题目：数组的交集
    给定两个数组，编写一个函数来计算它们的交集。
    示例 1:
        输入: nums1 = [1,2,2,1], nums2 = [2,2]
        输出: [2,2]
    示例 2:
        输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        输出: [4,9]
    说明：
        输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
        我们可以不考虑输出结果的顺序。
*/

/*
思路：

 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for(auto i : nums1){
            m[i]++;
        }
        for(auto i : nums2){
            if(m.find(i) != m.end() && --m[i] >= 0){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){

    system("pause");
    return 0;
}