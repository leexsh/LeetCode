#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-22 题目：括号的生成
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
    示例：
        输入：n = 3
        输出：[
                "((()))",
                "(()())",
                "(())()",
                "()(())",
                "()()()"
            ]

*/

/*
思路：
https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
 */

// 回溯 做减法
class Solution {
public:
    vector<string> vec;
    vector<string> generateParenthesis(int n) {
        if(n == 0){
            return vec;
        }
        dfs("", n,n);
        return vec;
    }
    void dfs(string str, int left, int right)
    {
//        左右括号都用完 push进去
        if(left == 0 && right == 0)
        {
            vec.push_back(str);
            return;
        }
//        左括号多 右括号少 要进行剪枝操作
        if(left > right){
            return;
        }
//        进行回溯
        if(left > 0)
        {
            dfs(str+"(", left - 1, right);
        }
        if(right > 0)
        {
            dfs(str+")", left, right - 1);
        }
    }
};

class Solution1 {
public:
    vector<string> vec;
    vector<string> generateParenthesis(int n) {

    }

};




int main(){
    return 0;
}