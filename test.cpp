#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode- 题目：

*/

/*
思路：

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> vec(2,-1);
    int i;
    for(i = 0; i < nums.size(); i++){
        if(nums[i] == target){
            vec[0] = i;
            break;
        }
    }
    if(i == nums.size()){
        vec[0] = -1;
    }
    int j;
    for(j = nums.size() - 1; j >= i; j--){
        if(nums[j] == target){
            vec[1] = j;
            break;
        }
    }
    return vec;
}
int main(){
    system("pause");
    return 0;
}