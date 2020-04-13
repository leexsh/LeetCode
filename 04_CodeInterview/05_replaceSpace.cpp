#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-5 题目：替换空格
    请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
    示例 1：
        输入：s = "We are happy."
        输出："We%20are%20happy."

*/

/*
思路：

 */
class Solution {
public:
    string replaceSpace(string s) {
        string str;
        for(auto i : s){
            if(i == ' '){
                str += "%20";
            } else{
                str += i;
            }
        }
        return str;
    }
};
int main(){

    system("pause");
    return 0;
}