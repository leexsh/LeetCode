#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-59 题目：螺旋矩阵II
    给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
    示例:
        输入: 3 
        输出:
        [
            [ 1, 2, 3 ],
            [ 8, 9, 4 ],
            [ 7, 6, 5 ]
        ]
*/

/*
思路：

 */
//左神的方法
vector<vector<int>> generateMatrix(int n) {
    // 2维数组的初始化 初始化为n*n的矩阵
    vector<vector<int>> vec(n, vector<int>());
    for(int i = 0; i < n; i++){
        vec[i].resize(n);
    }
    int a = 0;
    int b = 0;
    int c = vec.size() - 1;
    int d = vec[0].size() - 1;
    int count = 1;
    while(a <= c && b <= d){
        if(a == c){
            vec[a][b] = count++;
        }
        else
        {
            for(int i = b; i != d; i++){
                vec[a][i] = count++;
            }
            for(int i = a; i != c; i++){
                vec[i][d] = count++;
            }
            for(int i = d; i != b; i--){
                vec[c][i] = count++;
            }
            for(int i = c; i != a; i--){
                vec[i][b] = count++;
            }      
        }
        a++;
        b++;
        c--;
        d--;    
    }
  
    return vec;
}

//leetcode思路
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n,vector<int>());
    for(int i = 0; i < n; i++){
        matrix[i].resize(n);
    }
    int a = 0;
    int b = 0;
    int c = n-1;
    int d = n-1;
    int count = 1;
    while(1){
        for(int i = b; i <= d; i++){
            matrix[a][i] = count++;
        }
        if(++a > c) break;
        for(int i = a; i <= c; i++){
            matrix[i][d] = count++;
        }
        if(--d < b) break;
        for(int i = d; i >= b; i--){
            matrix[c][i] = count++;
        }
        if(--c < a){break;}
        for(int i = c; i >= a; i--){
            matrix[i][b] = count++;
        }
        if(++b > d){ break;}
    }
    return matrix;
}
int main(){
    vector<vector<int>> vec(4,vector<int>());
    for (int i = 0; i < 4; i++) {
	    vec[i].resize(4);
    }
    for(auto i : vec){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    system("pause");
    return 0;
}