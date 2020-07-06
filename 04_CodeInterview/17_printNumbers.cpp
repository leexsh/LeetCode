#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
//剑指offer-17 题目：打印从1到最大的n位数
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for (int i = 1, max = pow(10, n); i < max; ++i) {
            res.push_back(i);
        }
        return res;
    }
};
int main() {
    cout<<1e5<<endl;
    return -1;
}