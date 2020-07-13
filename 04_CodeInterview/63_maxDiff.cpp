#include "bits/stdc++.h"
using namespace std;
/*
 LeetCode- 题目：
剑指 Offer 63. 股票的最大利润
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？



示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
*/

/*
思路：

 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int max_diff = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int cur = prices[i] - min_price;
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
            max_diff = max(cur, max_diff);
        }
        return max_diff;
    }
};
int main(){

    system("pause");
    return 0;
}