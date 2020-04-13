#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-09 题目：栈make队列
    用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
    示例 1：
        输入：
        ["CQueue","appendTail","deleteHead","deleteHead"]
        [[],[3],[],[]]
        输出：[null,null,3,-1]
    示例 2：
        输入：
        ["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
        [[],[],[5],[2],[],[]]
        输出：[null,-1,null,null,5,2]
*/

/*
思路：

 */

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);

    }

    int deleteHead() {
       if(s2.empty()){
           if(s1.empty()){
               return -1;
           }
           while(!s1.empty())
           {
               s2.push(s1.top());
               s1.pop();
           }
       }
       int value = s2.top();
       s2.pop();
       return value;

    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main(){

    system("pause");
    return 0;
}