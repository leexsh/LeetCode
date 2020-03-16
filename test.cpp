#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode- 题目：

*/

/*
思路：

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    string compressString(string S) {
        string str = "";
        for(int i = 0; i < S.size(); i++)
        {
            int cnt = 0;
            int j = i;
            while(S[i] == S[j])
            {
                cnt++;
                j++;
            }
            str += S[i];
            str += to_string(cnt);
            i = j - 1;
        }
        return str.size() > S.size() ? S : str;
    }
};
// hash_map

int main(){
    system("pause");
    return 0;
}