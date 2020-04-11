#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-11 题目：旋转数组的最小值
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
    示例 1：
        输入：[3,4,5,1,2]
        输出：1
    示例 2：
        输入：[2,2,2,0,1]
        输出：0
*/

/*
思路：

 */

class Solution {
public:
    int find(vector<int> &nums, int left, int right)
    {
        int min = nums[left];
        for(int i = left; i <= right; i++)
        {
            if(nums[i] < nums[left]){
                min = nums[i];
            }
        }
        return min;
    }
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        int mid = 0;
        while(numbers[left] >= numbers[right]){
            mid = left + (right - left) /2;
            if(right - left == 1){
                mid = right;
                return numbers[mid];
            }
            if(numbers[low] == numbers[mid] && numbers[high] == numbers[mid])
            {
                return find(numbers, low, high);
            }
            if(numbers[mid] > numbers[left]){
                left = mid;
            }
            if(numbers[mid] < numbers[right]) {
                right = mid;
            }
        }
        return numbers[mid];
    }
};
int main(){

    system("pause");
    return 0;
}