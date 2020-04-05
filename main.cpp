#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//
class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};




string core(string s, int i , int j ){
    while(s[i] == s[j] && i >= 0 && j < s.size()){
        i--, j++;
    }
    return s.substr(i+1, j - i - 1);
}
string longestPalindrome(string s) {
    if(s.size() <= 1)
    {
        return s;
    }
    string str;
    for (int i = 0; i < s.size()  ; ++i) {
        string s1 = core(s, i, i);
        string s2 = core(s, i,i +1);
        string ss = s1.size() > s2.size() ? s1 : s2;
        str = str.size() > ss.size() ? str : ss;

    }
    return str;
//    return s.substr(start, maxlen);
}


int main() {
    string s = "babad";
    string str = longestPalindrome(s);
    cout<<str<<endl;

    return 0;
}