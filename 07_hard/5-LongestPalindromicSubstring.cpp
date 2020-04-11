#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-5 题目：最长回文子串

*/

/*
思路：

 */
// 暴力
class Solution {
public:
    string longestPalindrome(string s) {
        string ss="";
        for(int i = 0; i < s.size(); i++){
            string str = "";
            string restr = "";
            for(int j = i; j < s.size(); j++)
            {
                str += s[j];
                restr = str;
                reverse(restr.begin(), restr.end());
                if(str == restr){
                    ss = ss.size() > str.size() ? ss : str; 
                }
            }
        }
        return ss;
    }
};

// 动态规划
class Solution1 {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1){
            return s;
        }
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), true));
        int maxlen = 1;
        int index = 0;
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(s[i] == s[j]){
                    if(i - j < 3){
                        flag[i][j] = true;
                    } else{
                        flag[i][j] = flag[i- 1][j+1];
                    }
                }
                else{
                    flag[i][j] = false;
                }
                if(flag[i][j]){
                    if(i-j + 1 > maxlen){
                        index = j;
                        maxlen = i-j + 1;
                    }
                }

            }
        }
        return s.substr(index, maxlen);
    }
};

// 中心扩展法
class Solution2 {
public:
    string zhongxin(string s, int i, int j ){
        while(s[i] == s[j] && i >= 0 && j < s.size())
        {
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1){
            return s;
        }
        string str = "";
        for(int i = 0; i < s.size(); i++){
            string s1 = zhongxin(s,i,i);
            string s2 = zhongxin(s, i, i+1);
            string s3 = s1.size() > s2.size() ? s1 : s2;
            str = str.size() > s3.size() ? str : s3;
        }
        return str;
    }
};
int main(){

    system("pause");
    return 0;
}