#include "bits/stdc++.h"
using namespace std;
/*

*/

/*
思路：
221. 最大正方形
    在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
    示例:
        输入:
        1 0 1 0 0
        1 0 1 1 1
        1 1 1 1 1
        1 0 0 1 0

    输出: 4
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, 0));
        int res = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else if (matrix[i][j] == '1') {
                    if (i == 0) {
                        dp[i][j] = 1;
                    } else if (j == 0){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                    }
                }
                res = max(res, dp[i][j]);
            }
        }
        return res*res;
    }
};
int main(){

    system("pause");
    return 0;
}