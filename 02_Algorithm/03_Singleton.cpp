#include <iostream>
#include <mutex>
#include <thread>
using namespace std;




// 懒汉模式 绝对安全 在创建对象的时候就进行初始化
class Singleton1{
public:
    static Singleton1* getInstance()
    {
        return Singleton1;
    }
private:
    Singleton1(){}
    Singleton1(const Singleton1&);
    Singleton1& operator=(const Singleton1&);
    static Singleton1 *instance;
};
Singleton1 Singleton1::instance = new Singleton1;




// e汉模式 多线程下 非线程安全的
class Singleton
{
public:
    static Singleton* getInstance(){
        if (instance == nullptr) {
            instance = new Singleton;
            return instance;
        }
        return instance;
    }
private:
    static Singleton *instance;
    Singleton(){}
    Singleton(const Singleton &);
    Singleton& operator=(const Singleton&);

};
Singleton* Singleton::instance = nullptr;


mutex mt;
// 利用双检锁实现的线程安全的懒汉模式
class Singleton2
{
public:
    static Singleton2* getInstance()
    {
        if (instance == nullptr) {
            lock_guard<mutex> lg(mt);
            if (instance == nullptr) {
                instance = new Singleton2;
                return instance;
            }
        }
        return instance;
    }
private:
    Singleton2(){}
    Singleton2(const Singleton2&);
    Singleton2& operator=(const Singleton2&);
    static Singleton2 *instance;
};
Singleton2* Singleton2::instance = nullptr;

// 懒汉模式  双检锁 + 自动回收
class Singleton3
{
public:
    static Singleton3* getInstance()
    {
        if (instance == nullptr) {
            lock_guard<mutex> lg(mt);
            if (instance == nullptr) {
                instance = new Singleton3;
                return instance;
            }
        }
    }
    class GC{
        public:
        ~GC(){
            if (Singleton3::instance) {
                delete Singleton3::instance;
            }
        }
    };
private:
    Singleton3(){}
    Singleton3(const Singleton3&);
    Singleton3& operator=(const Singleton3&);
    static Singleton3 *instance;
    static GC gc;
}
Singleton3* Singleton3::instance = nullptr;

// 利用linux的pthread_once实现懒汉模式
class Singleton4
{
public:
    static Singleton4* getInstance()
    {
        pthread_once(&p_once, init);
        return instance;
    }
private:
    void init()
    {
        instance = new Singleton4;
    }
    Singleton4(){};
    Singleton4(const Singleton4&);
    Singleton4& operator=(const Singleton4&);
    static Singleton4 *instance;
    static pthread_once_t p_once;
}
Singleton4* Singleton4::instance  = nullptr;
pthread_once_t Singleton4::p_once = PTHREAD_ONCE_INIT;
int main() {


    return 0;
}
