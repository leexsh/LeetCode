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
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty())
        return false;
    int heng = matrix[0].size();
    int shu = matrix.size();
    int end = heng * shu - 1;
    int start = 0;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(matrix[mid/heng][mid%heng] == target){
            return true;
        }
        else if(matrix[mid/heng][mid%heng] < target){
            start = mid + 1;
        }
        else
        {
            /* code */
            end = mid - 1;
        }
    
    }
    return false;
}
int main(){
    // test();
    vector<vector<int>> vec{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    bool f = searchMatrix(vec, 3);
    cout<<f<<endl;
    system("pause");
    return 0;
}