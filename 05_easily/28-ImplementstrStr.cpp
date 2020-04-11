#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-28 题目：实现str
    实现 strStr() 函数。
        给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
    示例 1:
        输入: haystack = "hello", needle = "ll"
        输出: 2
    示例 2:
        输入: haystack = "aaaaa", needle = "bba"
        输出: -1

*/

/*
思路：

 */

// KMP算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty() || needle.empty())
        {
            return 0;
        }
        for(int i = 0; i  < haystack.size(); i++)
        {
            if(haystack[i] == needle[0]){
                cout<<needle.size()<<endl;
                string str = haystack.substr(i, needle.size());
                cout<<str<<endl;
                if(str == needle)
                {
                    return i;
                }
            }
        }
        return -1;

    }
};
class Solution1 {
public:
    int strStr(string haystack, string needle) {
        if((haystack.empty() && !needle.empty())||haystack.size() < needle.size()){
            return -1;
        }
        if(haystack.empty() || needle.empty()){
            return 0;
        }
        vector<int> next = getNext(needle);
        int i1 = 0, i2 = 0;
        while (i1 < haystack.size() && i2 < needle.size()){
            if(haystack[i1] == needle[i2]){
                i1++,i2++;
            } else
            {
                if(next[i2] == -1){
                    i1++;
                } else{
                    i2 = next[i2];
                }
            }
        }
        return i2 == needle.size() ? i1 - i2 : -1;
    }
    vector<int> getNext(string &str)
    {
        if(str.size() == 1){
            return vector<int>{-1};
        }
        vector<int> next(str.size(), 0);
        next[0] = -1;
        next[1] = 0;
        int i  = 2;
        int cn =0;
        while(i < str.size())
        {
            if(str[i - 1] == str[cn]){
                next[i++] = ++cn;
            }
            else if(cn > 0)
            {
                cn = next[cn];
            } else{
                next[i++] = 0;
            }
        }
        return next;
    }
};
int main(){
    string s = "hello";
    string ss = "ll";
    Solution s1;
    int x = s1.strStr(s,ss);
//    cout<<x<<endl;
    system("pause");
    return 0;
}