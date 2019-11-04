#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode 169 -题目：求众数
    给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
    你可以假设数组是非空的，并且给定的数组总是存在众数。
    示例 1:
        输入: [3,2,3]
        输出: 3
    示例 2:
        输入: [2,2,1,1,1,2,2]
        输出: 2
*/

/*
思路：
    见法1 法2
 */

// 借助map 时间复杂度O(n)
// int majorityElement(vector<int>& nums) {
//     unordered_map<int, int> m;
//     for(int i = 0; i < nums.size(); i++){
//         m[nums[i]]++;
//     }
//     int num = 0;//保存map的second
//     int ans = 0;//保存map的first
    
//     for(auto i = m.begin(); i != m.end(); i++){
//         if(i->second > num){
//             num = i->second;
//             ans = i->first;
//         }
//     }
//     return ans;
// }
//摩尔投票法
// 原理：在一个数组中一个元素出现的次数大于 n/2 = x,那也得必须要有x个元素才能抵消掉他，
// 但是2*x > n,因此剩下的元素一定是最多的那个。
int majorityElement(vector<int>& nums) {
    int ans = 0;
    int cand = nums[0];
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] == cand){
            ans++;
        }
        else if(ans == 0){
            cand = nums[i];
        }
        else{
            ans--;
        }
    }
    return cand;
}
int main(){
    vector<int> vec{2,2,1,1,1,2,2,2};
    int i = majorityElement(vec);
    cout<<"i = "<<i<<endl;
    system("pause");
    return 0;
}