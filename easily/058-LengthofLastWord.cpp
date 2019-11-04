#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode -58题目：最后一个单词的长度
    给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
    如果不存在最后一个单词，请返回 0 。
    说明：一个单词是指由字母组成，但不包含任何空格的字符串。
    示例:
        输入: "Hello World"
        输出: 5
*/

/*
思路：
    见法1和法2
 */

//法1.从后面找到最后一个不是空格的单词 从他往前找一个空格的大小 就是最后一个单词的大小
int lengthOfLastWord(string s) {
    if(s.size() == 0)
        return 0;

    int i = 0;
    int len = s.size() - 1;
    while(len >= 0 && s[len] == ' '){
        len--;
    }
    for(int j = len; j >= 0; j--){
        if(s[j] != ' ')
            i++;
        else
        {
            break;
        }
        
    }
    return i;
}

 //法2.用string的内置方法find_last_of() 先找到最后一个' '，把最后的' '都给去掉后， 再利用find_last_of()继续找单词前面的空格
 //减出来得到长度。 
int lengthOfLastWord(string s) {
    if(s.size() == 0)
        return 0;
    auto i = s.find_last_of(' ');
    while(i == s.length - 1){
        if(s.empty()) return 0;
        s.erase(i);
        i = s.find_last_of(' ');
    }
    return s.size() - i-1;
}
int main(){
    string s = "a ";
    string s1 = "Hello world";
    cout<<s1.size()<<endl;
    cout<<"------"<<endl<<lengthOfLastWord(s1)<<endl;
     cout<<"------"<<endl<<lengthOfLastWord(s1)<<endl;
    system("pause");
    return 0;
}