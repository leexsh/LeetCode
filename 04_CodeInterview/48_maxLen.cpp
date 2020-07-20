#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
剑指 Offer 48. 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。



示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*/

/*
思路：

 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int i = 0, j = 0;
        set<int> st;
        int res = 0;
        while (j < s.size()) {
            if (!st.count(s[j])) {
                st.insert(s[j++]);
                res = max(res, j - i);
            } else {
                st.erase(s[i++]);
            }
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}