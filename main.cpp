#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main(){
    string str("");
    for (int i = 0; i < 10; ++i) {
        str += to_string(i);
    }
    cout<<str<<endl;
    cout<<"cc"<<endl;
    return 0;
}