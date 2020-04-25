#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()){
            return 0;
        }
        int len = s.size() - 1;
        while(s[len] == ' ' && len >= 0)
        {
            len--;
        }
        int count = 0;
        for (int i = len; i >= 0 ; --i) {
            if(s[i] != ' '){
                count++;
            } else
                {
                    break;
                }
        }
        return count;

    }
};
int main() {
    priority_queue<int,vector<int>,greater<int>> que;

    que.push(3);
    que.push(6);
    que.push(2);
    que.push(1);
    while(!que.empty())
    {
        cout<<que.top();
        que.pop();
    }

    return 0;
}