#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-231 题目：2的幂
    给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
    示例 1:
        输入: 1
        输出: true
        解释: 2的0次幂 = 1
    示例 2:
        输入: 16
        输出: true
        解释: 2的4次幂 = 16
    示例 3:
        输入: 218   
        输出: false
*/

/*
思路：
    见1 2 3 4 
 */
// 1 递归
bool isPowerOfTwo1(int n) {
    if(n <= 0){
        return false;
    }
    else if(n == 1){
        return true;
    }        
    else{
        if(n % 2 == 0)
            return isPowerOfTwo1(n / 2);
        else 
            return false;
    }
}

// 2  循环
bool isPowerOfTwo2(int n) {
    if(n <= 0){
        return false;
    }
    else if(n == 1){
        return true;
    }        
    while(n % 2 == 0){
        n /= 2;
    }
    return n == 1;
}
// 3 循环
bool isPowerOfTwo3(int n) {
    if(n <= 0){
        return false;
    }
    else if(n == 1){
        return true;
    }        
    long long  int m = 1;
    while(m < n){
        m *= 2;
    }
    return m == n;
}

// 4
// 2的n次幂转为2进制正好是 1的后面全是0 比如 4 8 16  -> 100 1000 10000 
// 而对应的n-1正好除了第一位之外都是1 比如   3 7 15  -> 011 0111 01111
// 因此将n和n-1进行与运算的时候 如果结果是0那么就是2的幂 否则就不是
bool isPowerOfTwo4(int n) {
    if(n <= 0){
        return false;
    }
    return n&(n - 1) == 0;
}
int main(){

    system("pause");
    return 0;
}