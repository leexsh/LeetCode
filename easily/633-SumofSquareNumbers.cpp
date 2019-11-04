#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-633 题目：两数平方和
    给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
    示例1:
        输入: 5
        输出: True
        解释: 1 * 1 + 2 * 2 = 5
    示例2:
        输入: 3
        输出: False
*/

/*
思路：
    双指针
 */
bool judgeSquareSum(int c) {
    long long int i = 0, j = sqrt(c);
    while(i <= j){
        if((i*i + j*j) == c)
            return true;
        else if((i*i + j*j) < c){
            i++;
        }else{
            j--;
        }
    }
    return false;
}
int main(){

    system("pause");
    return 0;
}
