#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-16 题目：数值的整数次方
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
    示例 1:
        输入: 2.00000, 10
        输出: 1024.00000
    示例 2:
        输入: 2.10000, 3
        输出: 9.26100
    示例 3:
        输入: 2.00000, -2
        输出: 0.25000
    解释: 2-2 = 1/22 = 1/4 = 0.25

*/

/*
思路：

 */

class Solution {
public:
    double myPow(double x, int n) {
        long num = abs(n);

        double res = 1;
        while(num)
        {
            if(num & 1){
                res *= x;
            }
            x *= x;
            num >>= 1;

        }
        return n > 0 ? res : 1/res;
    }
};
class Solution1 {
public:
    double myPow(double x, int n) {
        int num = abs(n);
        if(n == 0)
        {
            return 1;
        }
        if(n == 1)
        {
            return x;
        }
        double res = 1.0;
        res = myPow(x, num>>1);
        res *= res;
        if(num % 2 == 1){
            res *= x;
        }
        return n > 0 ? res : 1/res;
    }
};
int main(){

    system("pause");
    return 0;
}