#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode- 题目：

*/

/*
思路：

 */

 bool isPerfectSquare(int num) {
    int low = 1;
    int high = num;
    while(low <= high){
        long mid  = low + (high - low)/2;
        if(num == mid *mid)
            return true;
        else if(mid *mid < num){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}
int main(){
  
    system("pause");
    return 0;
}