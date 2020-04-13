#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-15 题目：1的个数
    请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
    示例 1：
        输入：00000000000000000000000000001011
        输出：3
        解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
    示例 2：
        输入：00000000000000000000000010000000
        输出：1
        解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
    示例 3：
        输入：11111111111111111111111111111101
        输出：31
        解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
*/

/*
思路：

 */
// 每次计数1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0){
            return 0;
        }
        int count = 0;
        while(n)
        {
            if(n & 1 == 1){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};

// n与n-1
class Solution1 {
public:
    int hammingWeight(uint32_t n) {

        int count = 0;
        while(n)
        {
            count++;
            n = n&(n-1);
        }
        return count;
    }
};
int main(){

    system("pause");
    return 0;
}