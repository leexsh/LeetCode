#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-74 题目：搜索二维矩阵
    编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
    每行中的整数从左到右按升序排列。
	每行的第一个整数大于前一行的最后一个整数。
    示例 1:
        输入:
        matrix = [
            [1,   3,  5,  7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
        ]
        target = 3  
        输出: true
    示例 2:
        输入:
        matrix = [
            [1,   3,  5,  7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
        ]
        target = 13
        输出: false

*/

/*
思路：
    二分
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        {
            return false;
        }
        int m = matrix.size()-1;
        int n = 0;
        while (m >= 0 && n < matrix[0].size())
        {
            if(matrix[m][n] == target){
                return true;
            } else if(matrix[m][n] < target)
            {
                n++;
            }
            else
            {
                m--;
            }
        }
        return false;
    }
};
int main(){

    system("pause");
    return 0;
}