
#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-14 题目：最长公共前缀
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。
    示例 1:
        输入: ["flower","flow","flight"]
        输出: "fl"
    示例 2:
        输入: ["dog","racecar","car"]
        输出: ""
        解释: 输入不存在公共前缀。
    说明:
        所有输入只包含小写字母 a-z 
*/

/*
思路：
    
 */

// 水平选择 选择每个字符串的前i个 看看是否相等
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()){
        return "";
    }
    for(int i = 0; i < strs[0].size(); i++){
        char ch = strs[0][i];
        for(int j = 1; j < strs.size(); j++){
            if(i == strs[j].size() || ch != strs[j][i]){
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}
int main(){
    vector<string> v{"flower", "fly", "flight"};
    string i = longestCommonPrefix(v);
    cout<<"i:"<<i<<endl;
    system("pause");
    return 0;
}