#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-389 题目：找不同
    给定两个字符串 s 和 t，它们只包含小写字母。
    字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
    请找出在 t 中被添加的字母。
    示例:
        输入：
        s = "abcd"
        t = "abcde"
        输出：  
        e
        解释：
        'e' 是那个被添加的字母。
*/

/*
思路：
 1 2
 */
// hash的方法
char findTheDifference(string s, string t) {
    vector<int> vec(26,0);
    for(auto i : s){
        vec[i-'a']++;
    }
    char ch;
    for(auto i : t){
        vec[i - 'a']--;
        if(vec[i - 'a'] == -1){
            ch = i;
        }
    }
    return ch;
}
char findTheDifference(string s, string t) {
    unordered_map<char, int> m;
    for(auto i : s){
        m[i]++;
    }
    char ch;
    for(auto i : t){
        if(m[i] ==  0)
        {
            ch = i;
            break;
        }
        m[i]--;
    }
    return ch;
}
// 异或
char findTheDifference(string s, string t) {
    int res = 0;
    for(auto i : s){
        res^=i;
    }
    for(auto i : t){
        res^=i;
    }
    return (char)res;
}
int main(){

    system("pause");
    return 0;
}