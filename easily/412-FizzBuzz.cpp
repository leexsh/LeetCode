#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-412 题目：FizzBuzz
    写一个程序，输出从 1 到 n 数字的字符串表示。
    1. 如果 n 是3的倍数，输出“Fizz”；
    2. 如果 n 是5的倍数，输出“Buzz”；
    3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
    示例：
        n = 15,
        返回:
        [
            "1",
            "2",
            "Fizz",
            "4",
            "Buzz",
            "Fizz",
            "7",
            "8",
            "Fizz",
            "Buzz",
            "11",
            "Fizz",
            "13",
            "14",
            "FizzBuzz"
        ]
*/

/*
思路：
    。。。。
 */
vector<string> fizzBuzz(int n) {
      string s1 = "Fizz";
      string s2 = "Buzz";
      string s3 = "FizzBuzz";  
      vector<string> vec;
      for(int i = 1; i <= n; i++){
          if(i % 3 == 0 && i % 5 != 0){
              vec.push_back(s1);
          }
          else if(i % 3 != 0 && i % 5 == 0){
              vec.push_back(s2);
          }
          else if(i % 3 == 0 && i % 5 == 0){
              vec.push_back(s3);
          }
          else{
              vec.push_back(to_string(i));
          }
      }
      return vec;
}
int main(){

    system("pause");
    return 0;
}