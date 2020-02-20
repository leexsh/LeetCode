#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-79 题目：单词搜索
    给定一个二维网格和一个单词，找出该单词是否存在于网格中。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
    同一个单元格内的字母不允许被重复使用。
    示例:
        board =
        [
            ['A','B','C','E'],
            ['S','F','C','S'],
            ['A','D','E','E']
        ]
    给定 word = "ABCCED", 返回 true.
    给定 word = "SEE", 返回 true.
    给定 word = "ABCB", 返回 false.
*/

/*
思路：
    回溯
 */

bool coreDeal(vector<vector<char>>& board, int rows, int cols, int row, int col,
    string word, int &visitedLength, vector<bool> &pMark){
        if(word[visitedLength] == '\0'){
            return true;
        }
        bool hasPath = false;
        if(row >= 0 && row < rows && col >= 0 && col < cols &&
            word[visitedLength] == board[row][col] && 
            pMark[row * cols + col] == false){
                ++visitedLength;
                pMark[row * cols + col] = true;
                hasPath = coreDeal(board, rows, cols, row,col + 1,word, visitedLength,pMark) 
                    || coreDeal(board, rows, cols, row,col - 1,word,visitedLength,pMark)
                    || coreDeal(board, rows, cols, row + 1,col,word,visitedLength,pMark)
                    || coreDeal(board, rows, cols, row - 1,col,word,visitedLength,pMark);
                if(hasPath == false){
                    --visitedLength;
                    pMark[row *cols + col] = false;
                }
            }
            return hasPath;
}
bool exist(vector<vector<char>>& board, string word) {
    if(board.empty() || word.empty()){
        return false;
    }        
    int rows = board.size();
    int cols = board[0].size();

    vector<bool> pMark(rows*cols, 0);
    int visitedLength = 0;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            if(coreDeal(board, rows, cols,row,col,word,visitedLength, pMark)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> vec{{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
    string str = "see";
    // bool v = vec[1][1] == 'f';
    // cout<<v<<endl;
    bool b = exist(vec, str);
    system("pause");
    return 0;
}