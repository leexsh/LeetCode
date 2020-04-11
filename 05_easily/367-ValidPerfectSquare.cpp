#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-367 题目：有效的完全平方数
    给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
    说明：不要使用任何内置的库函数，如  sqrt。
    示例 1：
        输入：16
        输出：True
    示例 2：
        输入：14
        输出：False

*/

/*
思路：
    二分
 */

 bool isPerfectSquare(int num) {
    int low = 1;
    int high = num;
    while(low <= high){
        long mid  = low + (high - low)/2;
        if(num == mid *mid)
            return true;
        else if(mid *mid < num){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}
int main(){
  
    system("pause");
    return 0;
}