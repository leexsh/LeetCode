#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-72 题目：编辑距离
    给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
    你可以对一个单词进行如下三种操作：
        插入一个字符
        删除一个字符
        替换一个字符
    示例 1：
        输入：word1 = "horse", word2 = "ros"
        输出：3
    解释：
        horse -> rorse (将 'h' 替换为 'r')
        rorse -> rose (删除 'r')
        rose -> ros (删除 'e')
    示例 2：
        输入：word1 = "intention", word2 = "execution"
        输出：5
    解释：
        intention -> inention (删除 't')
        inention -> enention (将 'i' 替换为 'e')
        enention -> exention (将 'n' 替换为 'x')
        exention -> exection (将 'n' 替换为 'c')
        exection -> execution (插入 'u')
*/

/*
思路：
动态规划

    定义 dp[i][j]
        dp[i][j] 代表 word1 中前 i 个字符，变换到 word2 中前 j 个字符，最短需要操作的次数
        需要考虑 word1 或 word2 一个字母都没有，即全增加/删除的情况，所以预留 dp[0][j] 和 dp[i][0]
    状态转移
        增，dp[i][j] = dp[i][j - 1] + 1
        删，dp[i][j] = dp[i - 1][j] + 1
        改，dp[i][j] = dp[i - 1][j - 1] + 1
        按顺序计算，当计算 dp[i][j] 时，dp[i - 1][j] ， dp[i][j - 1] ， dp[i - 1][j - 1] 均已经确定了
        配合增删改这三种操作，需要对应的 dp 把操作次数加一，取三种的最小
        如果刚好这两个字母相同 word1[i - 1] = word2[j - 1] ，那么可以直接参考 dp[i - 1][j - 1] ，操作不用加一

 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> res(word1.size()+1, vector<int>(word2.size()+1,0));
        for (int i = 0; i < res.size(); ++i) {
            res[i][0] = i;
        }
        for (int j = 0; j < res[0].size(); ++j) {
            res[0][j] = j;
        }
        for (int k = 1; k < res.size(); ++k) {
            for (int i = 1; i < res[k].size(); ++i) {
                res[k][i] = min(res[k-1][i-1], min(res[k-1][i], res[k][i-1])) + 1;
                if(word1[k-1] == word2[i-1])
                {
                    res[k][i] = min(res[k][i], res[k-1][i-1]);
                }
            }
        }
        return res.back().back();
    }
};
int main(){

    system("pause");
    return 0;
}