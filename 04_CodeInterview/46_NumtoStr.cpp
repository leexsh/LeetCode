#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:
    输入: 12258
    输出: 5
    解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/

/*
思路：

 */
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int size = str.size();
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= size; ++i) {
            string substr = str.substr(i - 2, 2);
            if (substr >= "10" && substr <= "25") {
                dp[i] = dp[i-1] + dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[size];
    }
};
int main(){

    system("pause");
    return 0;
}