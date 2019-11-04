#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-66 题目：加1
    给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
    最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。
    示例 1:
        输入: [1,2,3]   
        输出: [1,2,4]
        解释: 输入数组表示数字 123。
    示例 2:
        输入: [4,3,2,1]
        输出: [4,3,2,2]
        解释: 输入数组表示数字 4321。
*/

/*
思路：
    如果一个数是9的话 就把他置为0 他前面的数+1，如果前面的数也是9的话，继续向前加。
    如果加到第一位是9的话，就在他前面插入个1。
 */
vector<int> plusOne(vector<int>& digits) {
    for(int i = digits.size()- 1; i >= 0; --i){
        if(digits[i] == 9){
            digits[i] = 0;
            if(i == 0){
                digits.insert(digits.begin(),1);
            }
            continue;
        }
        else{
            ++digits[i];
            break;
        }
    }
    return digits;
}


int main(){
    
    system("pause");
    return 0;
}