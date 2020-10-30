#include "bits/stdc++.h"
using namespace std;
/*

给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

示例 1：
    输入：[-4,-1,0,3,10]
    输出：[0,1,9,16,100]
示例 2：
    输入：[-7,-3,2,3,11]
    输出：[4,9,9,49,121]
*/

/*
思路：

 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size(), 0);
        for (int i = 0, j = A.size() - 1, pos = A.size() - 1; i <= j;) {
            if (A[i] * A[i] < A[j] * A[j]) {
                res[pos] = A[j] * A[j];
                j--;
            } else {
                res[pos] = A[i] * A[i];
                i++;
            }
            pos--;
        }
        return res;
    }
};
int main(){

    system("pause");
    return 0;
}