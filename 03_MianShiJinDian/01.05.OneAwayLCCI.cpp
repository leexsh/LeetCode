#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-0105 题目：一次编辑
    字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
    示例 1:
        输入:
        first = "pale"
        second = "ple"
        输出: True
    示例 2:
        输入:
        first = "pales"
        second = "pal"
        输出: False

*/

/*
思路：

 */

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int a = first.size() - second.size();
        if(a > 1 || a < -1)
        {
            return false;
        }
        bool flag = false;
        for (int i = 0, j = 0; i < first.size() && j < second.size(); ++i, ++j) {
            if(first[i] == second[j]){
                continue;
            }else if(flag){
                return false;
            }

            if(a == 1){
                j--;
            }
            else if(a == -1)
            {
                i--;
            }
            flag = true;
        }
        return true;
    }
};
int main(){

    system("pause");
    return 0;
}