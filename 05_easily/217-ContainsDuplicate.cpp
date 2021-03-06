#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-217 题目：存在重复元素
    给定一个整数数组，判断是否存在重复元素。
    如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
    示例 1: 
        输入: [1,2,3,1]
        输出: true
    示例 2:
        输入: [1,2,3,4]
        输出: false
    示例 3:
        输入: [1,1,1,3,3,4,3,2,4,2]
        输出: true
*/

/*
思路：
    1  2
 */
// 1.集合的思想
bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for(int i = 0; i < nums.size(); i++){
        if(s.count(nums[i]))
            return true;
        s.insert(nums[i]);
    }
    return false;
}
// 2.排序 判断两个相邻的元素是否相等
bool containsDuplicate(vector<int>& nums) {
    if(nums.size() == 0)
        return false;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] == nums[i + 1])
            return true;
    }
    return false;
}

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
};


int main(){

    system("pause");
    return 0;
}