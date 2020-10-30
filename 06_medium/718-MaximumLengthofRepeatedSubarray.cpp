#include "bits/stdc++.h"
using namespace std;
/*

*/

/*
思路：
给两个整数数组A和B，返回两个数组中公共的、长度最长的子数组的长度。

示例：
    输入：
        A: [1,2,3,2,1]
        B: [3,2,1,4,7]
        输出：3
    解释：
        长度最长的公共子数组是 [3, 2, 1] 。
       
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) {
            return 0;
        }
        int m = A.size() - 1;
        int n = B.size() - 1;
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int res = 0;
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 0;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}