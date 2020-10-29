#include "bits/stdc++.h"
using namespace std;
/*

*/

/*
思路：

 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size(), 0);
        for (int i = 0, j = A.size() - 1, pos = A.size() - 1; i <= j ;) {
            if (A[i] * A[i] < A[j] * A[j]) {
                res[pos] = A[j]*A[j];
                j--;
            } else {
                res[pos] = A[i] * A[i];
                i--;
            }
            pos--;
        }
    }
};
int main(){

    system("pause");
    return 0;
}