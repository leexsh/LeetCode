#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-10 题目：斐波那契数列

*/

/*
思路：

 */
class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return fib(n-1) + fib(n-2);
    }
};

class Solution1 {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 2; i <= n; ++i) {
            c = a+b;
            a = b;
            b = c;
//            b = a;
        }
        return c;
    }
};

int main(){

    system("pause");
    return 0;
}