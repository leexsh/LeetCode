#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-77 题目：组合
    给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
    示例:
        输入: n = 4, k = 2
        输出:
            [
                [2,4],
                [3,4],
                [2,3],
                [1,2],
                [1,3],
                [1,4],
            ]


*/

/*
思路：
    荷兰国旗问题
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0 || k > n){
            return res;
        }
        vector<int> path;
        dfs(n,k,1,path);
        return res;
    }
    void dfs(int n, int k ,int begin,vector<int> &path)
    {
        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= n; ++i) {
            path.push_back(i);
            dfs(n,k,i+1,path);
            path.pop_back();
        }
    }
};

int main(){

    system("pause");
    return 0;
}