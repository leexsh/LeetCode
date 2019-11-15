#include<vector>
#include<iostream>
#include<set>
using namespace std;
/* 
LeetCode- 题目：

*/

/*
思路：

 */

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vec;
    set<int> s;
    if(nums1.empty() || nums2.empty()){
        return vec;
    }   
    set<int> sn;
    if(nums1.size() > nums2.size())
    {
        for(auto i : nums2)
            sn.insert(i);
    }     
    else
    {
        for(auto i : nums1)
            sn.insert(i);
    }
    for(auto i : sn){
        int low = 0;
        int high = nums2.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums2[mid] == i){
                s.insert(i);
                break;
            }
            else if(i > nums2[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    for(auto i : s){
        vec.push_back(i);
    }
    // vec = 
    return vec;
}
int main(){
    vector<int> vec1{4, 9, 5};
    vector<int> vec2{9,4,9,8,4};
    vector<int> vec = intersection(vec1, vec2);
        // cout<<"location :"<< x<<endl;
    for(auto i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}