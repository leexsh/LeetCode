#include "bits/stdc++.h"
using namespace std;
/*
470. 用 Rand7() 实现 Rand10()
已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。
不要使用系统的 Math.random() 方法。
示例 1:
    输入: 1
    输出: [7]
示例 2:
    输入: 2
    输出: [8,4]
示例 3:
    输入: 3
    输出:  [8,1,10]

提示:
    rand7 已定义。
    传入参数: n 表示 rand10 的调用次数。
*/

/*
思路：

 */
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand7() {
        return 0;
    }
    int rand10() {
        int res = (rand7() - 1) * 7 + (rand7() - 1);
//        while (true) {
//            int res =(rand7() - 1) * 7 + (rand7() - 1);
//            if (res > 0 && res < 41) {
//                return res % 10 + 1;
//            }
//        }
        while (res > 39) {
            res = (rand7() - 1) * rand7() + (rand7() - 1);
        }
        return res % 10 + 1;
    }
};
int main(){

    system("pause");
    return 0;
}

while (true) {
int x = (rand7() - 1) * 7 + (rand7() - 1);
if (x >= 1 && x <= 40)
return x % 10 + 1;
}

