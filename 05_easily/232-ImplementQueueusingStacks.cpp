#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-232 题目：用栈实现队列
    使用栈实现队列的下列操作：  
	    push(x) -- 将一个元素放入队列的尾部。
	    pop() -- 从队列首部移除元素。
	    peek() -- 返回队列首部的元素。
	    empty() -- 返回队列是否为空。
    示例:
        MyQueue queue = new MyQueue();
        queue.push(1);
        queue.push(2);  
        queue.peek();  // 返回 1
        queue.pop();   // 返回 1
        queue.empty(); // 返回 false    
    说明:
	    你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
	    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
	    假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
*/

/*
思路：

 */
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
       s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // s2不空 不能进入 s1进的话 就要一次全部进入
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(){

    system("pause");
    return 0;
}