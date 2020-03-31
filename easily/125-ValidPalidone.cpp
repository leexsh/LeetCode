#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-125 题目：验证回文串

*/

/*
思路：

 */

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()){
            return false;
        }
        int i =0, j = s.size() - 1;
        while(i < j){
            while(!isalnum(s[i]) && i < j ){
                i++;
            }
            while(!isalnum(s[j]) && j > i){
                j--;
            }
            if(toupper(s[i]) != toupper(s[j])){
                return false;
            }
            i++, j--;
        }
        return true;
    }
};
int main(){

    system("pause");
    return 0;
}