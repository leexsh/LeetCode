#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-0102 题目：字符串重排
    给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
    示例 1：
        输入: s1 = "abc", s2 = "bca"
        输出: true
    示例 2：
        输入: s1 = "abc", s2 = "bad"
        输出: false
*/

/*
思路：

 */

// map
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        map<char, int > m;
//        mutset<char> s;
        for(auto i : s1)
        {
            m[i]++;
        }
//        if{}
        for(auto i : s2)
        {
            if(m[i] == 0)
            {
                return false;
            }
            m[i]--;
        }
        return true;
    }
};
int main(){

    system("pause");
    return 0;
}