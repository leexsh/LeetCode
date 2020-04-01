#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-171 题目：Execl表格序号
    给定一个Excel表格中的列名称，返回其相应的列序号。
    例如，
        A -> 1
        B -> 2
        C -> 3
        ...
        Z -> 26
        AA -> 27
        AB -> 28
        ...
    示例 1:
        输入: "A"
        输出: 1
    示例 2:
        输入: "AB"
        输出: 28
    示例 3:
        输入: "ZY"
        输出: 701
*/

/*
思路：

 */
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(auto i : s){
            int num = i - 'A' + 1;
            res = res * 26 + num;
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}