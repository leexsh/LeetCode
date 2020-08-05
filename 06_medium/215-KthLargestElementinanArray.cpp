#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-215 题目：数组中的第K个最大元素
    在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
    示例 1:
        输入: [3,2,1,5,6,4] 和 k = 2
        输出: 5
    示例 2:
        输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
        输出: 4
    说明:

*/

/*
思路：

 */
// 小根堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> vec(k,0);
        priority_queue<int,vector<int>,less<int>> que;
        for(auto i : nums)
        {
            if(que.size() < k){
                que.push(i);
            } else{
                if(i > que.top()){
                    que.pop();
                    que.push(i);
                }
            };
        }
        return que.top();
    }
};

class Solutio1n {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> dq(nums.begin(), nums.begin() + k);
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > dq.top()) {
                dq.pop();
                dq.push(nums[i]);
            }
        }
        return dq.top();
    }
};
int main(){

    system("pause");
    return 0;
}