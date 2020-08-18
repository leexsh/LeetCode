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
class Solution2{
public:
    string expends(string s, int i, int j)
    {
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
//        j-1 - (i+1) + 1 = j - i - 1;
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        if(s.size() < 2)
        {
            return s;
        }
        string ss("");
        for (int i = 0; i < s.size(); ++i) {
            string string1 = expends(s, i, i);
            string string2 = expends(s, i, i + 1);
            string sss = string1.size() > string2.size() ? string1 : string2;
            ss = ss.size() > sss.size() ? ss : sss;
        }

        return ss;

    }
};
int main(){

    system("pause");
    return 0;
}