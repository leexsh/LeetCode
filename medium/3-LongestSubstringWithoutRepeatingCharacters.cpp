#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-3 题目：无重复字符串的最长子串
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
    示例 1:
        输入: "abcabcbb"    
        输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    示例 2:
        输入: "bbbbb"   
        输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
    示例 3:
        输入: "pwwkew"
        输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

/*
思路：
    滑动窗口
    维持一个最大的窗口
 */
int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;
    int n = s.size();
    set<char> se;
    int res = 0;
    while (/* condition */i < n && j < n)
    {
        /* code */
        if(!se.count(s[j])){
            se.insert(s[j++]);
            res = max(res, j - i);
        }
        else
        {
            /* code */
            se.erase(s[i++]);
        }
        
    }
    
}
int main(){

    system("pause");
    return 0;
}