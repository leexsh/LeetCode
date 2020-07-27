#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/7/27.
//

// 归并排序
void Merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp(high - low + 1);
    int i = 0;
    int p1 = low, p2 = mid+1;
    while (p1 <= mid && p2 <= high)
    {
        temp[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
    }
    while (p1 <= mid) {
        temp[i++] = nums[p1++];
    }
    while (p2 <= high) {
        temp[i++] = nums[p2++];
    }
    for (int i = 0; i < temp.size(); i++) {
        nums[low + i] = temp[i];
    }
}
void Sort(vector<int> &nums, int low, int high)
{
    if (low == high) {
        return ;
    }
    int mid = low + ((high - low) >> 1);
    Sort(nums, low, mid);
    Sort(nums, mid+1, high);
    Merge(nums, low, mid, high);
}
void MergeSort(vector<int> &nums)
{
    if (nums.size() < 2) {
        return ;
    }
    Sort(nums, 0, nums.size() - 1);
}

int main() {


    return 0;
}