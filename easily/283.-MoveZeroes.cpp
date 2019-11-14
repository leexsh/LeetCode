#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-283 题目：移动0
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    示例:
        输入: [0,1,0,3,12]
        输出: [1,3,12,0,0]
    说明:
        必须在原数组上操作，不能拷贝额外的数组。
	    尽量减少操作次数。
*/

/*
思路：
    把每一个非0的数前移  后面补0d
    
 */

void moveZeroes(vector<int>& nums) {
    if(nums.size() < 1){
        return;
    }
    int count = 0;
    for(int i = 0; i <nums.size(); i++){
        if(nums[i] != 0){
            nums[count++] = nums[i];
        }
    }
    for(count; count < nums.size(); count++){
        nums[count] = 0;
    }
}
int main(){
    vector<int> vec{0,1,0,3,12};
    moveZeroes(vec);
    for(auto i : vec){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}