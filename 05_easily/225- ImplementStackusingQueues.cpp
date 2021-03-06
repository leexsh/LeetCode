#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-225 题目：用栈实现队列
    使用队列实现栈的下列操作：
    	push(x) -- 元素 x 入栈
	    pop() -- 移除栈顶元素
	    top() -- 获取栈顶元素
	    empty() -- 返回栈是否为空
    注意:
    	你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
	    你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
	    你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
*/

/*
思路：

 */
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    // 入栈
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // 出栈
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    /** Get the top element. */
    // 栈顶
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(val);
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    /** Returns whether the stack is empty. */
    // 栈空
    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }
        else
        {
            return false;

        }
    }
private:
    queue<int> q1;
    queue<int> q2;
};
int main(){

    system("pause");
    return 0;
}