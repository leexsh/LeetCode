#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
    给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
    示例 1:
        输入: "(()"
        输出: 2
    解释: 最长有效括号子串为 "()"

    示例 2:
        输入: ")()())"
        输出: 4
    解释: 最长有效括号子串为 "()()"

*/

/*
思路：

 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        int max_res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = 2;
                    if (i-2 >= 0) {
                        dp[i] = dp[i-2] + dp[i];
                    }
                } else if (dp[i-1] > 0){
                    if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(') {
                        if (i - dp[i-1] - 2 >= 0) {
                            dp[i] = dp[i - dp[i-1] - 2] + dp[i-1] + 2;
                        }else {
                            dp[i] = dp[i-1] + 2;
                        }
                    }
                }
            }
            max_res = max(max_res, dp[i]);
        }
        return max_res;
    }
};
int main(){

    system("pause");
    return 0;
}