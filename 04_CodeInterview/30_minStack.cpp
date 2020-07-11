#include "bits/stdc++.h"
using namespace std;
/*
LeetCode- 题目：
剑指 Offer 30. 包含min函数的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
示例:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.min();   --> 返回 -3.
    minStack.pop();
    minStack.top();      --> 返回 0.
    minStack.min();   --> 返回 -2.
*/

/*
思路：

 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (st.empty()) {
            st.push(x);
            st.push(x);
        } else {
            int min_value = x < st.top() ? x : st.top();
            st.push(x);
            st.push(min_value);
        }
    }
    void pop() {
        st.pop();
        st.pop();
    }

    int top() {
        int _min = st.top();
        st.pop();
        int top = st.top();
        st.push(_min);

        return  top;

    }

    int min() {
        return st.top();
    }

private:
    stack<int> st;
};

class MinStack1 {
public:

    MinStack1() {

    }

    void push(int x) {
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        } else {
            int _min = x < s2.top() ? x : s2.top();
            s2.push(_min);
        }
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();
    }

    int min() {
        return s2.top();

    }
private:
    stack<int> s1, s2;
};
int main(){

    system("pause");
    return 0;
}