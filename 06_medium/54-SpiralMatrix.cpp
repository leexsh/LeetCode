#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-54 题目：陀螺矩阵
    给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
    示例 1:
        输入:
        [
            [ 1, 2, 3 ],
            [ 4, 5, 6 ],
            [ 7, 8, 9 ]
        ]
        输出: [1,2,3,6,9,8,7,4,5]
    示例 2:
        输入:
        [
            [1, 2, 3, 4],
            [5, 6, 7, 8],
            [9,10,11,12]
        ]   
        输出: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

/*
思路：
    左神牛逼  一个框一个框的 读入
 */
vector<int> printNum(vector<vector<int>> &nums, int a, int b, int c, int d);
vector<int> spiralOrder1(vector<vector<int>>& matrix){
    vector<int> vec;
    if(matrix.empty()){
        return vec;
    }
    int a = 0;
    int b = 0;
    int c = matrix.size() - 1;
    int d = matrix[0].size() - 1;
    while(a <= c && b <= d){
        vector<int> v = printNum(matrix, a++, b++, c--, d--);
        for(auto i : v){
            vec.push_back(i);
        }
    }
    return vec;
}        
vector<int> printNum(vector<vector<int>> &nums, int a, int b, int c, int d){
    vector<int> vec;
    // 一行
    if(a == c){
        for(b; b <= d; b++){
            vec.push_back(nums[a][b]);
        }
    }
    // 一列
    else if(b == d){
        for(a; a <= c; a++){
            vec.push_back(nums[a][b]);
        }
    }
    else{
        int heng = b;
        int shu = a;
        while(heng != d){
            vec.push_back(nums[a][heng++]);
        }
        while(shu != c){
            vec.push_back(nums[shu++][d]);
        }
        while(heng != b){
            vec.push_back(nums[c][heng--]);
        }
        while(shu != a){
            vec.push_back(nums[shu--][b]);
        }
    }
    return vec;
}

//leetcode题解
vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> vec;
    if(matrix.empty()){
        return vec;
    }
    int a = 0;
    int b = 0;
    int c = matrix.size() - 1;
    int d = matrix[0].size() - 1;
    while(1){
        for(int i = b; i <= d; i++){
            vec.push_back(matrix[a][i]);
        }
        if(++a > c) break;//不能越界
        for(int i = a; i <= c; i++){
            vec.push_back(matrix[i][d]);
        }
        if(--d < b) break;//不能越界
        for(int i = d; i >= b; i--){
            vec.push_back(matrix[c][i]);
        }
        if(--c < a){break;}//不能越界
        for(int i = c; i >= a; i--){
            vec.push_back(matrix[i][b]);
        }
        if(++b > d){ break;}//不能越界
    }
    return vec;
}

int main(){
    system("pause");
    return 0;
}