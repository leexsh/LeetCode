#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mt;
void test1() 
{
    int i = 0;
    lock_guard<mutex> lg(mt);
    for (i; i < 20; ++i) {
        cout<<"test1: i = "<<i<<endl;
    }
}

void test2()
{
    int i = 50;
    lock_guard<mutex> lg(mt);
    for (i; i < 70; ++i) {
        cout<<"test2: i = "<<i<<endl;
    }
}
int main()
{
    thread td1(test1);
    thread td2(test2);

    td1.join();
    td2.join();
    return 0;
}