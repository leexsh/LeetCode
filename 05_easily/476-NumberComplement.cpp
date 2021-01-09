#include "bits/stdc++.h"
using namespace std;
/*
476. 数字的补数
给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。

    示例 1:
        输入: 5
        输出: 2
    解释: 5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
    示例 2:
        输入: 1
        输出: 0
    解释: 1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。

*/

/*
思路：

 */
class Solution {
public:
    int getOne(int num) {
        int res = 0;
        while (num) {
            res++;
            num &= (num - 1);
        }
        return res;
    }
    int findComplement(int num) {
        int cnt = getOne(num);
        return num ^ (long)((1 << cnt) - 1);
    }
};
int main(){
    Solution s;
    cout<<s.getOne(5)<<endl;
    system("pause");
    return 0;
}