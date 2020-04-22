#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-17 题目：电话号码的组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

/*
思路：

 */


// 回溯  深度遍历
class Solution {
public:
    unordered_map<char,string> map{
        {'2',"abc"},{'3',"def"},{'4',"ghi"},
        {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
        {'8',"tuv"},{'9',"wxyz"}

    };
    vector<string> res;
    string digits;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return res;
        }
        this->digits = digits;
        dfs("", 0);
        return res;
    }
    void dfs(string str, int index)
    {
        int size = this->digits.size();
        if(index == size)
        {
            res.push_back(str);
            return;
        }

//        先获取到字符
        char ch = this->digits[index];
        string s = map[ch];
//        dfs
        for(auto i : s)
        {
            dfs(str+i, index+1);
        }
        return;
    }
};

// 队列 广度遍历
class Solution1
{
    unordered_map<char,string> map{
            {'2',"abc"},{'3',"def"},{'4',"ghi"},
            {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
            {'8',"tuv"},{'9',"wxyz"}

    };
    vector<string> res;
    string digits;

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return res;
        }
        deque<string> deq;
        deq.push_back("");
//        广度遍历
        for (int i = 0; i < digits.size(); ++i) {
            string str = map[digits[i]];
//            获取到队列大小
            int size = deq.size();
            for (int j = 0; j < size; ++j) {
                string s = deq.front();
                deq.pop_front();
                for (int k = 0; k < str.size(); ++k) {
                    deq.push_back(s+str[k]);
                }
            }
        }
        while(!deq.empty()){
            res.push_back(deq.front());
            deq.pop_front();
        }
        return res;
    }
};


int main(){
    return 0;
}