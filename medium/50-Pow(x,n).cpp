#include <iostream>

using namespace std;
//
// Created by leexsh on 2020/3/28.
//

//Implement pow(x, n), which calculates x raised to the power n (xn).
//
//Example 1:
//
//Input: 2.00000, 10
//Output: 1024.00000
//Example 2:
//
//Input: 2.10000, 3
//Output: 9.26100
//Example 3:
//
//Input: 2.00000, -2
//Output: 0.25000
//Explanation: 2-2 = 1/22 = 1/4 = 0.25

// 超时
class Solution1 {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        int num = abs(n);
        double res = 1;
        for(int i = 0; i < num; i++){
            res *= x;
        }
        return n > 0 ? res : 1/res;
    }
};
//kuaisumi
class Solution2 {
public:
    double myPow(double x, int n) {
        int num = abs(n);
        double res = 1;
        while(num){
            if(num & 1 == 1){
                res *= x;
            }
            x *= x;
            num /= 2;
        }
        return n > 0 ? res : 1/res;
    }
};


int main() {


    return 0;
}