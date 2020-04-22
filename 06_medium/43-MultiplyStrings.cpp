#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-40 题目：组合总和II
    给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
    示例 1:
        输入: num1 = "2", num2 = "3"
        输出: "6"
    示例 2:
        输入: num1 = "123", num2 = "456"
        输出: "56088"
    说明：
        num1 和 num2 的长度小于110。
        num1 和 num2 只包含数字 0-9。
    num1 和 num2 均不以零开头，除非是数字 0 本身。
    不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

/*
思路：
 */

// 转化为long long 处理 超出位数
class Solution1 {
public:
    void stoi(string str, long long &num)
    {
        stringstream ss;
        ss<<str;
        ss>>num;
    }
    void itos(long long  num, string &str){
        stringstream ss;
        ss<<num;
        ss>>str;
    }
    string multiply(string num1, string num2) {
//        long long num;
        long long n1, n2;
        stoi(num1, n1);
        stoi(num2, n2);
        string str;
        itos(n1*n2, str);
        return str;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2=="0")
        {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int s1 = num1.size();
        int s2 = num2.size();
        vector<int> vec(s1+s2);
        for (int i = 0; i < s1; ++i) {
            for (int j = 0; j < s2; ++j) {
                vec[i+j] += (num1[i] - '0')*(num2[j] - '0');
            }
        }
        for (int k = 0; k < s1+s2; ++k) {
            if(vec[k] > 9)
            {
                int t = vec[k];
                vec[k] = t % 10;
                vec[k+1] += (t/10);
            }
        }

        int size = (vec[s1+s2 - 1] == 0 ? s1+s2- 2: s1+s2-1);
        string str="";
        while (size>=0)
        {
            str += (vec[size--] + '0');
        }
        return str;
    }
};


int main(){
    return 0;
}