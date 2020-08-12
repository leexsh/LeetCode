#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：131. 分割回文串
    给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
    返回 s 所有可能的分割方案。
    示例:
        输入: "aab"
        输出:
            [
                ["aa","b"],
                ["a","a","b"]
            ]
*/

/*
思路：

 */
class Solution {
public:
    vector<vector<string>> res;
    void dfs(string& str, vector<string>& path, int index)
    {
        if (index >= str.size()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < str.size(); ++i) {
            string temp = str.substr(index, i - index + 1);
            bool f = false;
            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j] != temp[temp.size() - 1 - j]) {
                    f = true;
                    break;
                }
            }
            if (f) continue;
            path.push_back(temp);
            dfs(str, path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return res;
        }
        vector<string> apth;
        dfs(s, apth, 0);
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}