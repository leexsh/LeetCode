#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-0101 题目：唯一字符串
    实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
    示例 1：
        输入: s = "leetcode"
        输出: false
    示例 2：
        输入: s = "abc"
        输出: true
    限制：
        0 <= len(s) <= 100
        如果你不使用额外的数据结构，会很加分
*/

/*
思路：

 */
class Solution {
public:
    bool isUnique(string astr) {
        set<char> s;
        for(auto i : astr){
            if(s.count(i)){
                return false;
            } else{
                s.insert(i);
            }
        }
        return true;
    }
};
int main(){

    system("pause");
    return 0;
}