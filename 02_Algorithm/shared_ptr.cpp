#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2020/4/9.
//
/*
 * shared_ptr的实现
 *
 * */

// 以int为例子
class shared_ptr{
public:
//    空参构造 构造一个空指针
    shared_ptr():ptr(nullptr), count(nullptr){

    }
//    有参构造
    shared_ptr(shared_ptr *p):ptr(p->ptr), count(new int(1)){}

//    拷贝构造函数
    shared_ptr(const shared_ptr & shared_obj)
    {
        count = &(++*shared_obj.count);
        ptr = shared_obj.ptr;
    }
//  拷贝赋值运算符
    shared_ptr &operator=(shared_ptr &shared_obj){
        if(&shared_obj == this){
            return  *this;
        }
//        将该对象赋值另一个对象
        ++*shared_obj.count;
//        该对象的引用计数-1
        if(ptr && --*this->count == 0){
            delete ptr;
            delete count;
        }
        this->ptr = shared_obj.ptr;
        count = shared_obj.count;
        return *this;
    }

//    析构函数
    ~shared_ptr(){
        if(ptr && --*this->count == 0){
            delete ptr;
            delete count;
        }
    }
    int getCount()
    {
        return *count;
    }
    int *operator->(){
        return this->ptr;
    }
    int &operator*()
    {
        return *ptr;
    }


private:
    int *ptr;   // 指针
    int *count; // 计数
};

int main() {
    shared_ptr<int> ptr = make_shared(1);


    return 0;
}