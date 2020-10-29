#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-347 题目：前k个高频元素
    给定一个非空的整数数组，返回其中出现频率前k高的元素。
    示例 1:
        输入: nums = [1,1,1,2,2,3], k = 2
        输出: [1,2]
    示例 2:
        输入: nums = [1], k = 1
        输出: [1]
    说明：
        你可以假设给定的k总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
        你的算法的时间复杂度必须优于 O(n log n) ,n是数组的大小。
*/

/*
思路：

 */
struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> que;
        for(auto i : nums){
            m[i]++;
        }
        for(auto ite = m.begin(); ite != m.end(); ite++){
            que.push(make_pair(ite->first, ite->second));
            if(que.size() > k){
                que.pop();
            }
//            if(que.size() == k){
//                if(ite->second > que.top().second){
//                    que.pop();
//                    que.push(make_pair(ite->first, ite->second));
//                } else{
//                    que.push(make_pair(ite->first, ite->second));
//                }
//            }
        }
        vector<int> vec;
        while(!que.empty()){
            vec.push_back(que.top().first);
            que.pop();
        }
        return vec;
    }
};
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto i : nums){
            m[i]++;
        }
        vector<pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](pair<int,int> &a, pair<int,int> &b){return a.second > b.second;});
        vector<int> res;
        auto a = vec.begin();
        while (k--)
        {
            res.push_back(a->first);
            a++;
        }
        return res;
    }
};

int main(){
    vector<int> nums{1,1,1,2,2,3};
    Solution s;
    vector<int>  v = s.topKFrequent(nums, 2);
    system("pause");
    return 0;
}