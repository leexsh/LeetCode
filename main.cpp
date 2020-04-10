#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//


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