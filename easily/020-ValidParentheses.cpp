#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode 20-题目有效的括号：
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
    有效字符串需满足：
        左括号必须用相同类型的右括号闭合。
	    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。
    示例 1:
        输入: "()"
        输出: true
    示例 2:
        输入: "()[]{}"
        输出: true
    示例 3:
        输入: "(]"
        输出: false
    示例 4:
        输入: "([)]"
        输出: false
    示例 5:
        输入: "{[]}"    
        输出: true
*/

/*
思路：
        很明显，肯定是用到栈的相关内容，当遇到左括号的时候进行入栈，当遇到右括号的时候，比对右括号是否与栈顶的元素相同
    相同则出栈，不相同则返回False，最后查看栈的大小，若为空则是true，否则false。
 */
bool isValid(string s) {
    // 奇数的序列s肯定不满足 返回false
    if(s.size() % 2 != 0)
        return false;
    //用容器替代栈
    vector<char> vec;
    // 遍历
    for(auto i : s){
        //左括号进容器
        if(i == '(' || i == '[' || i == '{'){
            vec.push_back(i);
        }
        else{
            //右括号进行比对
            if(!vec.empty()){
                if(i == ')' && vec.back() != '(') return false;
                if(i == ']' && vec.back() != '[') return false;
                if(i == '}' && vec.back() != '{') return false;
                vec.pop_back();
            }
        }
    }
    return vec.empty() ? true : false;
}
int main(){
    string s = "[][][]()(){}{}";
    bool flag = isValid(s);
    if(flag)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    system("pause");
    return 0;
}