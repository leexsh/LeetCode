#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums,path);
        return res;
    }
    void dfs(vector<int> &nums, vector<int> &path)
    {
        if(nums.size() == path.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(find(path.begin(), path.end(), nums[i]) == path.end())
            {
                path.push_back(nums[i]);
                dfs(nums,path);
                path.pop_back();
            }


        }
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