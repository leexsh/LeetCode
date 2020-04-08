#include "bits/stdc++.h"
using namespace std;
/*
LeetCode- 题目：机器人运动范围
    地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
    示例 1：
        输入：m = 2, n = 3, k = 1
        输出：3
    示例 1：
        输入：m = 3, n = 1, k = 0
        输出：1
    提示：
        1 <= n,m <= 100
        0 <= k <= 20
*/

/*
思路：

 */

class Solution {
public:
    int getNum(int x){
        int res = 0;
        while(x){
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    int moveCountCore(int k, int m, int n, int row, int col, vector<vector<bool>> &flag)
    {
        int count = 0;
        if(row >= 0 && col >= 0 && row < m && col < n && getNum(row) + getNum(col) <= k && flag[row][col] == false)
        {
            flag[row][col] = true;
            count = 1 + moveCountCore(k, m, n, row + 1, col,flag)
                      + moveCountCore(k, m,n,row - 1, col,flag)
                      + moveCountCore(k, m, n, row, col + 1, flag)
                      + moveCountCore(k, m, n, row, col - 1, flag);
        }
        return count;
    }
    int movingCount(int m, int n, int k) {
        if(k < 0 || m <= 0 || n <= 0)
        {
            return 0;
        }
        vector<vector<bool>> flag(m, vector<bool>(n,false));
        return moveCountCore(k, m, n, 0, 0, flag);
    }
};



int main(){

    system("pause");
    return 0;
}