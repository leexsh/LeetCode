#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//
class Solution {
public:
    int rows, cols;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        if (board.size() == 0 || word.size() == 0 || rows < 1 || cols < 1) {
            return false;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int len){
        if (i >= 0 && i < rows && j >= 0 && j < cols && board[i][j] == word[len]) {
            len++;
            if (len == word.size()) {
                return true;
            }
            char temp = board[i][j];
            board[i][j] = '.';
            if (dfs(board, word, i, j-1, len) || dfs(board, word, i, j+1, len)
              ||dfs(board,word, i-1, j, len) || dfs(board, word, i+1, j, len)) {
                return true;
            }
            board[i][j] = temp;
            len--;
        }
        return false;
    }
};
int main() {
    cout<<2e5<<endl;
    return 0;
}