#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-67 题目：二进制相加
    给你两个二进制字符串，返回它们的和（用二进制表示）。
    输入为 非空 字符串且只包含数字 1 和 0。
    示例 1:
        输入: a = "11", b = "1"
        输出: "100"
    示例 2:
        输入: a = "1010", b = "1011"
        输出: "10101"
*/

/*
思路：

 */

class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size();
        int bsize = b.size();
        while (asize < bsize)
        {
            a = '0' + a;
            asize++;
        }

        while (bsize < asize)
        {
            b = '0' + b;
            bsize++;
        }

//      进位
        int carray = 0;
        for (int i = asize-1; i >= 0; --i) {
            int sum = a[i] - '0' + b[i] - '0' + carray;
            a[i] = sum % 2 + '0';
            carray = sum / 2;
        }
        if(carray > 0)
        {
            a = "1" + a;
        }
        return a;
    }
};
int main(){

    system("pause");
    return 0;
}