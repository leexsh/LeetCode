#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode 27 -题目：移除元素
    给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
    示例 1:
        给定 nums = [3,2,2,3], val = 3,
        函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
        你不需要考虑数组中超出新长度后面的元素。    
    示例 2:
        给定 nums = [0,1,2,2,3,0,4,2], val = 2,
        函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
    注意这五个元素可为任意顺序。
    你不需要考虑数组中超出新长度后面的元素

*/

/*
思路：
    两种方法如下
 */
// 方法一：利用stl的erase()方法
int removeElement(vector<int>& nums, int val) {
    auto i = nums.begin();
    // 遍历一遍 搞定
    while(i != nums.end){
        //erase()方法之后 会返回一个指向后一个元素的迭代器 因此不需要再将迭代器++
        if(*i == val){
            nums.erase(i);
        }
        else{
            i++;
        }
    }
    return nums.size();
}

// 方法2：我们只需要一个变量用来计数，然后遍历原数组，如果当前的值和给定值不同，
// 我们就把当前值覆盖计数变量的位置，并将计数变量加1。
int removeElement(vector<int>& nums, int val) { 
    int k = 0;
    for(int i = 0; i < nums.size; i++){
        if(nums[i] != val){
            nums[k++] = nums[i];
        }
    }
    return k;
}   
int main(){

    system("pause");
    return 0;
}