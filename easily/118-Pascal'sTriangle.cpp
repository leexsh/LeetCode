#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-118 题目：杨辉三角
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。
*/

/*
思路：

 */
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    if(numRows == 0)    return ans; //若numRows为空，返回空数组
    for(int i = 0; i < numRows; ++ i ) //给数组一个个赋值
    {
        for(int j = 0; j <= i; ++ j)
        {
            if(j == 0 || j == i) //若是左右两边的边界，赋值为1
                ans[i].push_back(1);
            else
                ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]); //否则赋值为该位置左上与右上的和
        }
    }
    return ans;
}
int main(){

    system("pause");
    return 0;
}