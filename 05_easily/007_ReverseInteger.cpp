#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-7 题目：整数翻转
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
    示例 1:
        输入: 123
        输出: 321
    示例 2:
        输入: -123
        输出: -321
    示例 3:
        输入: 120
        输出: 21
*/

/*
思路：

 */

class Solution {
public:
    int reverse(int x) {
        int y = 0;
        while(x){
            if(y > INT_MAX / 10 || y < INT_MIN / 10)
            {
                return 0;
            }
            y *= 10;
            y += (x % 10);
            x /= 10;
        }
        return y;
    }
};
int main(){

    system("pause");
    return 0;
}