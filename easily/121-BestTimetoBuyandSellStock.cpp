#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-121 题目：买股票的最佳时机一
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。  
    如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
    注意你不能在买入股票前卖出股票。
    示例 1:
        输入: [7,1,5,3,6,4]
        输出: 5
        解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
    注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
    示例 2:
        输入: [7,6,4,3,1]   
        输出: 0
        解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

/*
思路：

 */
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int max = INT_MIN;
    int min = prices[0];
    for(int i = 0; i < prices.size(); ++i){
        int cur = prices[i] - min;
        if(prices[i] < min){
            min = prices[i];
        }
        max = max(max,   cur);
    }
    return max;
}
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int ans = 0;
    for(int i = 0; i < prices.size();++i){
        for(int j = i+1; j < prices.size(); ++j){
            if(prices[j] - prices[i] > ans){
                ans = prices[j] - prices[i];
            }
        }
    }
    return ans > 0 ? ans : 0;
}
int main(){
    vector<int> vec{7,6,4,3,1};
    cout<<maxProfit(vec)<<endl;
    system("pause");
    return 0;
}