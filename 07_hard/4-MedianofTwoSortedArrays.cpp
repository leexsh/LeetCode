#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/3/25.
//
/*
LeetCode-4 题目：寻找两个有序数组的中位数
    给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
    请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
    你可以假设 nums1 和 nums2 不会同时为空。
    示例 1:
        nums1 = [1, 3]
        nums2 = [2]
        则中位数是 2.0
    示例 2:
        nums1 = [1, 2]
        nums2 = [3, 4]
        则中位数是 (2 + 3)/2 = 2.5
*/

/*
思路：

 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            vec.push_back(nums1[i] > nums2[j] ? nums2[j++] : nums1[i++]);
        }
        while (i < n1){
            vec.push_back(nums1[i++]);
        }
        while (j < n2) {
            vec.push_back(nums2[j++]);
        }
        return vec.size() & 1 ? vec[vec.size() / 2] : (vec[vec.size() / 2 - 1] + vec[vec.size()/ 2]) / 2.0;
    }
};
int main() {
    vector<int> v1{1,2};
    vector<int> v2{3,4};
    Solution s;
    double d = s.findMedianSortedArrays(v1,v2);
    cout<<d<<" aa"<<endl;

    return 0;
}