#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-18 题目：四数之和
    给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
    使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
    注意：
        答案中不可以包含重复的四元组。
    示例：
        给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
        满足要求的四元组集合为：
        [
            [-1,  0, 0, 1],
            [-2, -1, 1, 2],
            [-2,  0, 0, 2]
        ]
*/

/*
思路：
    跟三数之和差不多
 */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> vec;
    int size = nums.size() - 1;
    // 排个序
    sort(vec.begin(), vec.end());
    //最外层循环 先选一个数
    for(int i = 0; i <= size - 3; i++){
        // 去掉重复的数
        if(i > 0 && nums[i - 1] == nums[i]){
            continue;
        }
        //下面跟三个数之和差不多
        for(int j = i + 1; j <= size - 2; j++){
            // 去掉跟nums[j]重复的
            if(j > i + 1 && nums[j - 1] == nums[j]){
                continue;
            }
            int L = j + 1;
            int R = size;
            while(L < R){
                int sum = nums[i] + nums[j] + nums[R] + nums[L];
                // 两数相等
                if(sum == target){
                    vec.push_back({nums[i], nums[j], nums[L], nums[R]});
                    while(L < R && nums[L + 1] == nums[L]){L++;}
                    while(L < R&& nums[R-1] == nums[R]){R--;}
                    R--;
                    L++;
                }else if(sum > target){R--;}
                else if(sum < target){L++;}
            }
        }
    }
    return vec;
    
    

}
int main(){
    vector<int> v{1,0,-1,0,2,-2};
    vector<vector<int>> vec;
    vec = fourSum(v, 0);
    for(auto i : vec){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}