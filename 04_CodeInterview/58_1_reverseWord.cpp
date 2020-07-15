#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
剑指 Offer 58 - I. 翻转单词顺序
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
*/

/*
思路：

 */

// the sky is blue
// blue is sky the
class Solution {
public:
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (i < s.size() && s[i] == ' ') ++i;
            if (i == s.size()) { break;}
            int j = i;
            while (j < s.size() && s[j] != ' ') { ++j;}
            reverse(s.begin() + i, s.begin() + j);
            if (k) {s[k++] = ' ';}
            while (i < j) {s[k++] = s[i++];}
        }
        s.erase(s.begin()+k, s.end());
        reverse(s.begin(), s.end());

        return s;
    }
};



int main(){

    system("pause");
    return 0;
}