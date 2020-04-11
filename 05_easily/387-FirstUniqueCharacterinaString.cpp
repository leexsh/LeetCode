#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-387 题目：字符串中第一个唯一字符
    给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
    案例:
        s = "leetcode"  
        返回 0.
        s = "loveleetcode", 
        返回 2.
*/

/*
思路：
    映射的方法
 */
int firstUniqChar(string s) {
    vector<int> v(26, 0);
    int i;
    for(i = 0; i < s.length(); i++){
        v[s[i] - 'a']++;
    }
    for(i = 0; i < s.length(); i++){
        if(v[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}
int firstUniqChar(string s) {
    unordered_map<char, int> m;
    for(auto i : s){
        if(m[i] > 0)
            m[i]++;
        else
        {
            m[i] = 1;
        }
    }
    for(int i = 0; i < s.length(); i++){
        if(m[s[i]] == 1){
            return i;
        }
    }
    return -1;
}
int main(){

    system("pause");
    return 0;
}