#include "bits/stdc++.h"
using namespace std;
/*
LeetCode- 题目：
剑指 Offer 49. 丑数
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
    示例:
        输入: n = 10
        输出: 12
    解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
*/

/*
思路：

 */
class Solution {
public:
    bool core(int n)
    {
        if (n == 1) {
            return true;
        }
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            }else if (n % 3 == 0) {
                n /= 3;
            }else if (n % 5 == 0) {
                n /= 5;
            }else {
                return false;
            }
        }
        return true;
    }
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        int res =0;
        int i = 1;
        while (n)
        {
            if (core(i)) {
                n--;
                res = i ;
            }else {
                i++;
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; ++i) {
            int a2 = dp[a] * 2, b2 = dp[b]*3, c2 = dp[c]*5;
            dp[i] = min(a2,min(b2,c2));
            if (dp[i] == a2) {a++;}
            if (dp[i] == b2) {b++;}
            if(dp[i] == c2){c++;}
        }
        return dp[n-1];
    }
};
int main(){

    system("pause");
    return 0;
}