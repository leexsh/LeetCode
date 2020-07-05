#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n-1;
        }
        int count = n / 3;
        int remain = n % 3;
        if (remain == 0) {
            return pow(3, count);
        }
        if (remain == 1) {
            return pow(3, count - 1) * 4;
        }
        if(remain == 2) {
            return pow(3, count) * 2;
        }
        return 0;
    }
};
class Solution1 {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int res = 1;
        while (n > 4) {
            res *= 3, n-=3;
        }
        return res * n;
    }
};
int main() {
    cout<<1e5<<endl;
    return -1;
}