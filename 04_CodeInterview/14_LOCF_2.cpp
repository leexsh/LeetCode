#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        long res = 1;
        while (n > 4) {
            res *= 3;
            res %= 1000000007;
            n -= 3;
        }
        return (res * n) %1000000007;
    }
};

int main() {
    cout<<1e5<<endl;
    return -1;
}