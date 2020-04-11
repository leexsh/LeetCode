#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-342 题目：4的幂
    给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
    示例 1:
        输入: 16    
        输出: true
    示例 2:
        输入: 5
        输出: false

*/

/*
思路：
    见1 2 3 4
 */
// 1 循环
bool isPowerOfFour1(int num) {
    if(num < 1)
        return false;
    if(num == 1)
        return true;
    int m = 1;
    while(m < num){
        m *= 4;
    }
    return m == num;
}

// 2 循环
bool isPowerOfFour2(int num) {
    if(num < 1)
        return false;
    if(num == 1)
        return true;
    while(num % 4 == 0){
        num /= 4;
    }
    return num == 1;
}

// 3 递归
bool isPowerOfFour3(int num) {
    if(num < 1)
        return false;
    if(num == 1)
        return true;
    else{
        if(num % 4 == 0)
            return isPowerOfFour3(num /= 4);
        else 
            return false;
    }
}

// 4
// 4的幂也一定是2的幂 并且4的幂次方的数的二进制表示 1 的位置都是在奇数位。
// 比如4 100 （1 在第 3 位） 16 10000（1 在第 5 位） 64 1000000（1 在第 7 位）
// 可以使用位运算：将这个数与特殊的数做位运算。这个特殊的数有如下特点：
    // 它的二进制表示中奇数位为 1 ，偶数位为 0
    // 符合这两个条件的二进制数是：1010101010101010101010101010101 即 Ox55555555
bool isPowerOfFour4(int num) {
    if(num <= 0){
        return false;
    }
    // 判断是不是2的幂
    if((num&(num - 1)) != 0)
        return false;
    // 判断奇数位是不是1
    if((num & 0x55555555) == num)
        return true;
    else
    {
            return false;
    }
    
}
int main(){

    system("pause");
    return 0;
}