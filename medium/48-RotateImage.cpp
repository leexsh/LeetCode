#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-48 题目：旋转图像
    给定一个 n × n 的二维矩阵表示一个图像。
    将图像顺时针旋转 90 度。
    说明：
        你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
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
    示例 2:
        给定 matrix =
        [
            [ 5, 1, 9,11],
            [ 2, 4, 8,10],
            [13, 3, 6, 7],
            [15,14,12,16]
        ], 
        原地旋转输入矩阵，使其变为:
        [   
            [15,13, 2, 5],
            [14, 3, 4, 1],
            [12, 6, 8, 9],
            [16, 7,10,11]
        ]
*/

/*
思路：
    左神方法 四条边 翻完就可以了
 */
void rotate(vector<vector<int>>& matrix) {
    int a = 0;
    int b = 0;
    int c = matrix.size() - 1;
    int d = matrix[0].size() - 1;
    while(a < c && b < d){
        calculation(matrix, a++, b++, c--, d--);
    }
}
void calculation(vector<vector<int>>& matrix, int a, int b, int c, int d){
    int edge = d - b;
    for(int i = 0; i != edge; i++){
        int temp = matrix[a][b+i];
        matrix[a][b + i] = matrix[c - i][b];
        matrix[c - i][b] = matrix[c][d - i];
        matrix[c][d - i] = matrix[a + i][d];
        matrix[a + i][d] = temp;
    }
}
int main(){

    system("pause");
    return 0;
}