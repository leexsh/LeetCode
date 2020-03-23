#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-5 题目：最长回文子串

*/

/*
思路：

 */

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
int main(){

    system("pause");
    return 0;
}