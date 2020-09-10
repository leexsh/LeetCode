#include "bits/stdc++.h"
using namespace std;
/*
168. Excel表列名称
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
    ...
    示例 1:
        输入: 1
        输出: "A"
    示例 2:
        输入: 28
        输出: "AB"
    示例 3:
        输入: 701
        输出: "ZY"
*/

/*
思路：

 */
class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }
        string str("");
        while (n)
        {
            n -= 1;
            str += ('A' + n % 26);
            n /= 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
int main(){

    system("pause");
    return 0;
}