#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) :val(value), left(nullptr), right(nullptr){}
};
class Solution {
public:
    string core(string s, int i, int j)
    {
        while (s[i] == s[j] && i >= 0 && j < s.size()) {
            --i;
            ++j;
        }
        // j-1-(i+1)
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        string ss("");
        for (int i = 0; i < s.size(); ++i) {
            string s1 = core(s, i, i);
            string s2 = core(s, i, i+1);
            string str = s1.size() > s2.size() ? s1 : s2;
            ss = ss.size() > str.size() ? ss : str;
        }
        return ss;
    }
};
int main() {
    Solution s1;
    s1.longestPalindrome("babad");
    return 0;
}