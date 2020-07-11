#include "bits/stdc++.h"
using namespace std;
/*
LeetCode- 题目：
剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。



示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
*/

/*
思路：

 */
class Solution {
public:
    vector<int> res;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k > arr.size() || k <= 0) {
            return res;
        }
        priority_queue<int, vector<int>,less<int>> que(arr.begin(), arr.begin() + k);
        for (int i = k; i < arr.size(); ++i) {
            if (arr[i] < que.top()) {
                que.pop();
                que.push(arr[i]);
            }
        }
        while (!que.empty()) {
            res.push_back(que.top());
            que.pop();
        }
        return res;
    }
};
class Solution1 {
public:
    vector<int> res;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.empty() || k > arr.size() || k <= 0) {
            return res;
        }
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
int main(){

    system("pause");
    return 0;
}