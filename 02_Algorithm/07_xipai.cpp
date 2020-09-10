#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/8/23.
//
// 洗牌算法
//n * n
void xipai1(vector<int>& nums, vector<int> &res)
{
    srand((unsigned )time(NULL));
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int k = rand() % nums.size();
        res.push_back(nums[k]);
        nums.erase(nums.begin() + k);
    }
}

//n
void xipai2(vector<int>& nums)
{
    srand((unsigned )time(NULL));
    for (int i = nums.size() - 1; i >= 0; ++i) {
//        int k = rand() % i;
        swap(nums[rand() % i + 1], nums[i]);
    }
}

int main() {


    return 0;
}