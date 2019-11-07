#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-326 题目：3的幂
    给定一个整数，写一个函数来判断它是否是 3 的幂次方。 
    示例 1:
        输入: 27    
        输出: true
    示例 2:
        输入: 0
        输出: false
    示例 3:
        输入: 9
        输出: true
    示例 4:
        输入: 45
        输出: false
*/

/*
思路：
    循环和递归
 */
// 循环
bool isPowerOfThree1(int n) {
    if(n == 0)
        return false;
    if(n == 1)
        return true;
    int m = 1;
    while(m < n){
        m *= 3;
    }
    return m == n;
}

// 循环
bool isPowerOfThree2(int n) {
    if(n == 0)
        return false;
    if(n == 1)
        return true;
    while(n % 3 == 0){
        n /= 3;
    }
    return n == 1;
}

// 递归
bool isPowerOfThree3(int n) {
    if(n == 0)
        return false;
    else if(n == 1)
        return true;
    else{
        if(n % 3 == 0){
            return isPowerOfThree3(n /= 3);
        }
        else return false;
    }
}

int main(){

    system("pause");
    return 0;
}