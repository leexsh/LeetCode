#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-49 题目：字母的异位词分组
    给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
    示例:
    输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
    输出:
        [
            ["ate","eat","tea"],
            ["nat","tan"],
            ["bat"]
        ]
    说明：
        所有输入均为小写字母。
        不考虑答案输出的顺序。*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty()){
            return res;
        }
        unordered_map<string, vector<string>> map;
        for(auto i : strs)
        {
           string s = i;
           sort(s.begin(), s.end());
           map[s].push_back(i);
        }
        for(auto i : map)
        {
            res.push_back(i.second);
        }
        return res;
    }
};


int main(){

    system("pause");
    return 0;
}