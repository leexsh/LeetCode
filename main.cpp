#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
class A{
public:
    int a;
    char b;
    int c;
};

class B : virtual A{
public:
    int bv;
//    char cc;
};
int main() {
    cout<<sizeof(int)<<endl;
    cout<<sizeof(B)<<endl;
    return 0;
}