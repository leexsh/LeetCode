#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
/* 
LeetCode-349 题目：两个数组的交集
    给定两个数组，编写一个函数来计算它们的交集。
    示例 1:
        输入: nums1 = [1,2,2,1], nums2 = [2,2]
        输出: [2]
    示例 2:
        输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        输出: [9,4]
    说明:
        输出结果中的每个元素一定是唯一的。
	    我们可以不考虑输出结果的顺序。
*/

/*
具体思路：
    集合的思想
*/
// 用集合
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vec;
    if(nums1.empty() || nums2.empty()){
        return vec;
    }   
    set<int> sn1(nums1.begin(), nums1.end());
    set<int> sn2(nums2.begin(), nums2.end());
    for(auto i : sn1){
        if(sn2.count(i)){
            vec.push_back(i);
            sn2.erase(i);
        }
    }
    return vec;
}
// 利用set的交集函数
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vec;
  
    set<int> sn1(nums1.begin(), nums1.end());
    set<int> sn2(nums2.begin(), nums2.end());
    set<int> s;
    set_intersection(sn1.begin(), sn1.end(), sn2.begin(), sn2.end(),inserter(s, s.begin()));
    for(auto i : s){
        vec.push_back(i);
    }
    return vec;
}
int main(){
    vector<int> vec1{4, 9, 5};
    vector<int> vec2{9,4,9,8,4};
    vector<int> vec = intersection2(vec1, vec2);
        // cout<<"location :"<< x<<endl;
    for(auto i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}