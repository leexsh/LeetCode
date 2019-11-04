#include<iostream>
#include<vector>
#include"bits/stdc++.h"
using namespace std;
/* 
LeetCode1-两数之和：
	给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
	你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

	示例:
	给定 nums = [2, 7, 11, 15], target = 9

	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]
*/

/*
思路：
	暴力求解 循环遍历 找到两个数的和为target  直接加入到容器中 返回
 */
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> vec;
	for (int i = 0; i != vec.size() - 1; i++) {
		for (int j = i + 1; j != vec.size(); j++) {
			if (nums[i] + nums[j] == target) {
				vec.push_back(i);
				vec.push_back(j);
				return vec;
			}
		}
	}
	return vec;
}
//利用stl中的map
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	vector<int> vec;
	int i;
	//建立值和下标的映射；
	for(i = 0; i < nums.size(); ++i){
		m[nums[i]] = i;
	}
	//根据值去找下标
	for(i = 0;i<nums.size(); i++){
		int n = target - nums[i];
		if(m.count(n) && m[n] != i){
			vec.push_back(i);
			vec.push_back(m[n]);
			break;
		}
	}
	return vec;
}
int main(){
vector<int> nums{ 2,7,11,15 };
	vector<int> vec;
	vec = twoSum(nums, 9);

	for (auto i : vec) {
		cout << i << " ";
	}
    system("pause");
    return 0;
}