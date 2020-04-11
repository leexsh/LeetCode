#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-0104 题目：回文


*/

/*
思路：

 */

class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> set;
        for(auto i : s)
        {
            if(set.count(i)){
                set.erase(i);
            } else{
                set.insert(i);
            }
        }
        return set.size() <= 1;
    }
};
int main(){

    system("pause");
    return 0;
}