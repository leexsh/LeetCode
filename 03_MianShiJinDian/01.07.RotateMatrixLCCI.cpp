#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-0107 题目：矩阵旋转
    给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
    不占用额外内存空间能否做到？
    示例 1:
        给定 matrix =
        [
            [1,2,3],
            [4,5,6],
            [7,8,9]
        ],
        原地旋转输入矩阵，使其变为:
        [
            [7,4,1],
            [8,5,2],
            [9,6,3]
        ]
*/

/*
思路：

 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto i : matrix){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        for (int k = 0; k < matrix.size(); ++k) {
            for (int i = 0; i < matrix[k].size() / 2; ++i) {
                swap(matrix[k][i], matrix[k][matrix[k].size() - i - 1]);
            }
        }
    }
};
int main(){

    system("pause");
    return 0;
}