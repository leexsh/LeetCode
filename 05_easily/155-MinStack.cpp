#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-155 题目：最小栈
    设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。O(1)
	push(x) -- 将元素 x 推入栈中。
	pop() -- 删除栈顶的元素。
	top() -- 获取栈顶元素。
	getMin() -- 检索栈中的最小元素。

*/

/*
思路：
    见 法1 法2
 */
// 法1：借助辅助栈  一个栈来保存数据 另一个栈来保存最小值
class MinStack1 {
public:
    stack<int> s;   //数据栈
    stack<int> minS;    //辅助栈
    
    MinStack1() {}
    
    void push(int x) 
    {
       s.push(x);
       if(minS.empty() || minS.top() > x)
        {
            minS.push(x);
        }
        else{
            minS.push(minS.top());
        }
    }
    
    void pop() {
      s.pop();
      minS.pop();
    }
    
    int top() {
       return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

// 法2 利用一个栈 将数据和最小值都入到一个栈中，数据在当前最小值的下面
class MinStack2 {
public:
    stack<int> s;
    
    MinStack2() {}
    
    void push(int x) 
    {
       if(s.empty())
       {
           s.push(x);
           s.push(x);
       }
       else
       {
           int top = s.top();
           s.push(x);
           if(top > x)
           {
               s.push(x);
           }
           else
           {
               s.push(top);
           }
       }
    }
    
    void pop() {
       s.pop();
       s.pop();
    }
    
    int top() {
      int min = s.top();
      s.pop();
      int top = s.top();
      s.push(min);
      return top;
    }
    
    int getMin() {
        return s.top();
    }
};
int main(){

    system("pause");
    return 0;
}