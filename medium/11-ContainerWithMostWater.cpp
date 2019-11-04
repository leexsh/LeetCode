#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode- 题目：盛最多水的容器
    https://leetcode-cn.com/problems/container-with-most-water/
        给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
    在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
        说明：你不能倾斜容器，且 n 的值至少为 2。

        图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
    示例:
        输入: [1,8,6,2,5,4,8,3,7]
        输出: 49
*/

/*
思路：
    见1  2
 */
// 暴力 双层循环遍历
int maxArea(vector<int>& height) {
    int max = 0;
    for(int i = 0; i < height.size() - 1; ++i){
        for(int j = i + 1; j < height.size(); ++j){
            int ans = height[i] > height[j] ? height[j] * (j - i) : height[i] * (j - i);
            if(ans > max)
                max = ans;
        }
    }
    return max;
}
// 双指针 一头一尾 谁小移动谁 
int maxArea1(vector<int>& height) {
    int max = 0;
    int i = 0, j = height.size() - 1;
    while(i < j){
        int ans = height[i] > height[j] ? height[j] * (j - i) : height[i] * (j - i);
        if(ans > max)
            max = ans;
        if(height[i] > height[j])
            j--;
        else{
            i++;
        }
    }
    return max;
}
int main(){

    system("pause");
    return 0;
}