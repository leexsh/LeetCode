#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//
// Created by leexsh on 2020/4/23.
//

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> res(m, vector<long>(n,0));
        res[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                if(i)
                {
                    res[i][j] += res[i-1][j];
                }
                if(j){
                    res[i][j] += res[i][j-1];
                }
            }
        }
        return res[m-1][n-1];
    }
};
int main() {

    return 0;
}