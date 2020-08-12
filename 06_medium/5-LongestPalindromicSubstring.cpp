#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-5 题目：最长回文子串
    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
    示例 1：
        输入: "babad"
        输出: "bab"
        注意: "aba" 也是一个有效答案。
    示例 2：
        输入: "cbbd"
        输出: "bb"
*/

/*
思路：

 */

// 暴力 超出时间限制
class Solution1 {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)
        {
            return s;
        }
        string res;
        for (int i = 0; i < s.size() ; ++i) {
            string temp;
            for (int j = i; j < s.size(); ++j) {
                temp += s[j];
                string retemp = temp;
                reverse(retemp.begin(), retemp.end());
                if(temp == retemp){
                    res = res.size() > temp.size() ? res : temp;
                }
            }
            temp.clear();
        }
        return res;
    }
};


// 动态规划
//https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zhong-xin-kuo-san-dong-tai-gui-hua-by-liweiwei1419/
class Solution2 {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
        {
            return s;
        }
//       最大长度
        int maxlen = 1;
//        起始位置
        int start = 0;
//        记录的二维数组
        vector<vector<bool>> flag(s.size(), vector<bool >(s.size(), true));

        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
//                两个字符相等
                if(s[i] == s[j])
                {
//                    距离小于3 一定是回文
                    if((i - j) < 3){
                        flag[i][j] = true;
                    }
//                    两个字符相等且距离大于3 要看去掉两个字符的字符串是否为回文
                    else
                    {
                        flag[i][j] = flag[i - 1][j+1];
                    }
                } else{
                    flag[i][j] = false;
                }
//                  回文
                if(flag[i][j]){
                    int curlen = i - j + 1;
//                    跟最大的比较
                    if(curlen > maxlen)
                    {
                        maxlen = curlen;
                        start = j;
                    }
                }
            }
        }
//        返回
        return s.substr(start, maxlen);
    }
};

// 中心扩展法
//https://blog.csdn.net/daidaineteasy/article/details/86238047
class Solution3 {
public:
    string expends(string s, int i, int j)
    {
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
//        i+1 到 j - (i + 1) == i + 1 到 j - i - 1
//          (j - 1) - (i + 1) + 1 = j - i - 1
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        if(s.size() < 2)
        {
            return s;
        }
        string ss("");
        for (int i = 0; i < s.size(); ++i) {
            string string1 = expends(s, i, i);
            string string2 = expends(s, i, i + 1);
            string sss = string1.size() > string2.size() ? string1 : string2;
            ss = ss.size() > sss.size() ? ss : sss;
        }

        return ss;

    }
};
int main(){
    string ss = "vilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    Solution1 s1;
    string sss = s1.longestPalindrome(ss);
    cout<<sss<<endl;
    Solution2 s2;
    string sss2 = s2.longestPalindrome(ss);
    cout<<sss2<<endl;
    system("pause");
    return 0;
}