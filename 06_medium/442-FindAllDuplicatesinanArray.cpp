#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-442 题目：数组中的重复元素
    给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
    找到所有出现两次的元素。
    你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
    示例：
    输入:
        [4,3,2,7,8,2,3,1]
    输出:
        [2,3]
*/

/*
思路：

 */
// set
vector<int> findDuplicates1(vector<int>& nums) {
    vector<int> vec;
    if(nums.size() < 0){
        return vec;
    }        
    set<int> s;
    for(auto i : nums){
        if(s.count(i)){
            vec.push_back(i);
        }
        else
        {
            s.insert(i);
        }
        
    }
    return vec;
}
// 方法2
vector<int> findDuplicates2(vector<int>& nums) {
    vector<int> vec;
    if(nums.size() < 0){
        return vec;
    }
    for(int i = 0; i < nums.size(); i++){
        while(nums[i] != i+1){
            if(nums[i] == nums[nums[i] - 1]){
                // 容易添加重复元素
                vec.push_back(nums[i]);
                break;
            }
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp; 
        }
    }
    return vec;
}

int main(){
    vector<int> vec{4,3,2,7,8,2,3,1};
    vector<int> vec1 = findDuplicates2(vec);
    for(auto i : vec1){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}