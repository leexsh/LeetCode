#include <iostream>
#include <deque>
#include <mutex>
#include <condition_variable>
using namespace std;
//
// Created by leexsh on 2020/8/8.
//

// 堵塞队列
class BlockQueue{
private:
    deque<int> dq;
    mutex mt;
    condition_variable not_empty;
    condition_variable not_full;
    int size;
public:
    BlockQueue(int s) : size(s){}
    void push(int val) {
        unique_lock<mutex> lg(mt);
        while (size < dq.size())
        {
            not_empty.wait(lg);
        }
        dq.push_back(val);
        not_full.notify_all();
    }

    int pop()
    {
        unique_lock<mutex> lg(mt);
        while (dq.empty()) {
                not_full.wait(lg);
        }
        int val = dq.front();
        dq.pop_front();
        not_empty.notify_all();
        return val;
    }
};

int main() {


    return 0;
}