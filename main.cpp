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
    TreeNode(int value) :val(value), left(nullptr), right(nullptr){}
};

int main() {
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    cout<<"1- "<<a<<endl;
    cout<<"2- "<<a+1<<endl;
    cout<<"3- "<<a[1]<<endl;
    cout<<"4- "<<&a[0]<<endl;
    cout<<"5- "<<&a<<endl;
    cout<<"6- "<<&a[0] + 1<<endl;
    cout<<"7- "<<a+1<<endl;
    cout<<"8- "<<&a+1<<endl;
    cout<<"9- "<<*(a+1)<<endl;
    cout<<"10- "<<*(&a+1)<<endl;
    return 0;
}