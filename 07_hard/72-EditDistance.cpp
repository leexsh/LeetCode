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