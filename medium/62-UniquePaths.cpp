#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-62 题目：不同的路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
思路：

 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 && n <= 0){
            return  0;
        }
        vector<vector<int >> vec(m,vector<int>(n,1));
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++){
                vec[i][j] = vec[i-1][j] + vec[i][j - 1];
            }
        }
        return vec[m-1][n-1];
    }
};
int main(){

    system("pause");
    return 0;
}