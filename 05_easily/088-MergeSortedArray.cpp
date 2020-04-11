#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode 88-题目：合并两个有序数组
    给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
    说明:
	    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
	    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
    示例:
        输入:
            nums1 = [1,2,3,0,0,0], m = 3
            nums2 = [2,5,6],       n = 3
        输出: [1,2,2,3,5,6]
*/

/*
思路：
    见法1和法2
 */
//法1.借助辅助空间 进行操作 在辅助空间中排完序，再拷贝到nums1中
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> vec;
    int i = 0, j = 0;
    while(i != m && j != n){
        if(nums1[i] < nums2[j]){
            vec.push_back(nums1[i]);
            ++i;
        }
        else if(nums1[i] > nums2[j]){
            vec.push_back(nums2[j]);
            ++j;
        }else{
            vec.push_back(nums1[i]);
            vec.push_back(nums2[j]);
            ++i;
            ++j;
        }
    }
    while(i != m){
        vec.push_back(nums1[i]);
        i++;
    }
    while(j != n){
        vec.push_back(nums2[j]);
        j++;
    }
    nums1 = vec;
}
//先全吧元素都拷贝到nums1中，再利用stl提供的sort()方法进行排序
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = 0; i < n; i++){
        nums1[m] = nums2[i];
        m++;
    }
    sort(nums1.begin(), nums1.end());
}
//法3：两个数组从后往前 先放大的 再放小的 一直放完
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while(i >= 0 &&j >= 0){
        if(nums1[i] > nums2[j])nums1[k--] = nums1[i--];
        else{
            nums1[k--] = nums2[j--];
        }
    }
    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
}
int main(){

    system("pause");
    return 0;
}