#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-0106 题目：字符串压缩
    字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
    示例1:
        输入："aabcccccaaa"
        输出："a2b1c5a3"
    示例2:
        输入："abbccd"
        输出："abbccd"
        解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

*/

/*
思路：

 */

class Solution {
public:
    string compressString(string S) {
        string s;
        int i = 0;
        for (int i = 0; i < S.size(); ++i) {
            int count = 0;
            for(int j = i; j < S.size(); j++){
                if(S[j] == S[i]){
                    count++;
                } else{
                    break;
                }
            }
            s += s[i];
            s += to_string(count);
            i = j - 1;
        }
        return s.size() < S.size() ? s : S;
    }
};
int main(){

    system("pause");
    return 0;
}