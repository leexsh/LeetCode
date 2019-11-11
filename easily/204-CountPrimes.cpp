#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-204 题目：计算质数
    统计所有小于非负整数 n 的质数的数量。   
    示例:
        输入: 10
        输出: 4
        解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

/*
思路：
    见下面
 */
//判断是否为质数
bool isPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
// 暴力解法 时间很长
int countPrimes1(int n) {
    if(n < 2){
        return 0;
    }
    int count = 0;
    for(int i = 2; i < n; i++){
        if(isPrime(i))
            count++;
    }   
    return count; 
}

//埃氏筛选法 就是把每个质数的倍数都给筛选出来
int countPrimes2(int n) {
    if(n < 2){
        return 0;
    }
    //筛选数组 不是质数的置为false
    vector<bool> bvec(n, true);
    int count = 0;
    for(int i = 2; i < n; i++){
        if(bvec[i]){
            for(int j = i * 2; j < n; j += i){
                bvec[j] = false;
            }
        }
    }  
    // true的就是质数 筛选出来 
    for(int i = 2; i < n; ++i){
        count += bvec[i] ? 1 : 0;
    }
    return count; 
}

//改进 省去了for循环
int countPrimes3(int n) {
    if(n < 2){
        return 0;
    }
    //筛选数组 不是质数的置为false
    vector<bool> bvec(n, true);
    int count = 0;
    for(int i = 2; i < n; i++){
        if(bvec[i]){
            count++;
            for(int j = i * 2; j < n; j += i){
                bvec[j] = false;
            }
        }
    }  
    return count; 
}
int main(){

    system("pause");
    return 0;
}