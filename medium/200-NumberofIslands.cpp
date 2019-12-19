#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-200 题目：岛屿的数量
    给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
    一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
    示例 1:
        输入:
        11110
        11010
        11000
        00000
        输出: 1
    示例 2:
        输入:
        11000
        11000
        00100
        00011
        输出: 3

*/

/*
思路：
    左神牛逼 岛的感染问题
    如果一个坐标是1 就把跟他相连的1 全部改成2 
    就看看改几次  就是几个岛
 */
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()){
        return 0;
    }        
    int res =  0;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            if(grid[i][j] == '1'){
                // 感染的函数
                infect(grid, i, j, grid.size(), grid[0].size());
                res++;
            }
        }
    }
    return res;
}

void infect(vector<vector<char>> &nums, int i, int j, int L, int W){
    // 终止条件 递归
    if(i < 0 || j < 0 || i >= L || j >= W || nums[i][j] != '1'){
        return ;
    }
    // 将所有的1 改成2
    nums[i][j] = '2';
    // 递归感染上下左右
    infect(nums, i - 1, j , L, W);
    infect(nums, i + 1, j , L, W);
    infect(nums, i, j - 1, L, W);
    infect(nums, i, j + 1, L, W);
}
int main(){

    system("pause");
    return 0;
}