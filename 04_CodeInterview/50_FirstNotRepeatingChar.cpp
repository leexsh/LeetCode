#include "bits/stdc++.h"
using namespace std;
/*
LeetCode- 题目：剑指 Offer 50. 第一个只出现一次的字符
   在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
   示例:
       s = "abaccdeff"
       返回 "b"
       s = ""
       返回 " "
*/

/*
思路：

 */


class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) {
            return ' ';
        }
        map<char, int> m;
        for(char ch : s){
            m[ch]++;
        }
        for (char ch : s) {
            if (m[ch] == 1) {
                return ch;
            }
        }
        return ' ';
    }
};
int main(){

    system("pause");
    return 0;
}