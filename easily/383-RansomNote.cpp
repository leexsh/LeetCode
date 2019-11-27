#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-383 题目：赎金信
    给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
    判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
    如果可以构成，返回 true ；否则返回 false。
    (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
    注意：
        你可以假设两个字符串均只含有小写字母。
        canConstruct("a", "b") -> false
        canConstruct("aa", "ab") -> false
        canConstruct("aa", "aab") -> true

*/

/*
思路：
    集合的方法
 */
bool canConstruct1(string ransomNote, string magazine) {
    unordered_map<char, int> m;
    for(int i = 0; i < magazine.length(); i++){
        m[magazine[i]]++;
    }
    for(int i = 0; i <ransomNote.length(); i++){
        m[ransomNote[i]]-=1;
        if(m[ransomNote[i]] < 0)
            return false;
    }
    return true;
}

bool canConstruct(string ransomNote, string magazine) {
    vector<int> hash(26,0);
    int i = 0;
    for(i; i < magazine.length(); i++){
        hash[magazine[i]-'a']++;
    }
    for(i = 0; i < ransomNote.length(); i++){
        hash[ransomNote[i] - 'a']--;
        if(hash[ransomNote[i] - 'a'] < 0){
            return false;
        }
    }
    return true;
}
int main(){

    system("pause");
    return 0;
}