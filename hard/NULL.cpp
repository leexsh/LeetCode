#include<iostream>
#include<vector>

using namespace std;
// 还没有做任何一道Hard难度的题目
int print(vector<int> &vec){
    for(auto i : vec){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> vec{12,3,4,4};
    print(vec);
    cout<<"asd"<<endl;
    system("pause");
    return 0;
}