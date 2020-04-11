#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-1228 题目：各位数字之积和各位数字和的差
    给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。
    示例 1：
        输入：n = 234   
        输出：15    
    解释：
        各位数之积 = 2 * 3 * 4 = 24 
        各位数之和 = 2 + 3 + 4 = 9 
        结果 = 24 - 9 = 15
    示例 2：
        输入：n = 4421  
        输出：21
    解释： 
        各位数之积 = 4 * 4 * 2 * 1 = 32 
        各位数之和 = 4 + 4 + 2 + 1 = 11 
        结果 = 32 - 11 = 21
*/

/*
思路：

 */
int subtractProductAndSum(int n) {
    int ji = 1;
    int add = 0;
    while(n != 0){
        // int x = n % 10;
        ji *= n % 10;
        add += n % 10;
        n = n / 10;
    }
    return ji - add;
}
int main(){

    system("pause");
    return 0;
}