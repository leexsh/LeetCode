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

 */
// 循环
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

// 循环
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

// 递归
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

bool isPowerOfFour4(int num) {

}
int main(){

    system("pause");
    return 0;
}