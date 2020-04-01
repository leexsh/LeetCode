#include "bits/stdc++.h"
using namespace std;
/*
LeetCode-146 题目：LRU缓存机制
    运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作：
    获取数据 get 和 写入数据 put 。
    获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
    写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，
    从而为新的数据值留出空间。
    进阶:
        你是否可以在 O(1) 时间复杂度内完成这两种操作？
    示例:
//        LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
//        cache.put(1, 1);
//        cache.put(2, 2);
//        cache.get(1);       // 返回  1
//        cache.put(3, 3);    // 该操作会使得密钥 2 作废
//        cache.get(2);       // 返回 -1 (未找到)
//        cache.put(4, 4);    // 该操作会使得密钥 1 作废
//        cache.get(1);       // 返回 -1 (未找到)
//        cache.get(3);       // 返回  3
//        cache.get(4);       // 返回  4
//*/

/*
思路：

 */
class LRUCache {
public:
    LRUCache(int capacity) {
        this->size = capacity;
    }


    int get(int key) {
//        找key
        auto ite = map.find(key);
//        没找到
        if(ite == map.end()){
            return -1;
        }
//        获取到位置
        pair<int, int> kv = *map[key];
//        先清除
        cache.erase(map[key]);
//        在加入到链表头部
        cache.push_front(kv);
//          更新位置
        map[key] = cache.begin();
//        返回value
        return kv.second;
    }

    void put(int key, int value) {
        auto ite = map.find(key);
//        不存在缓存中
        if(ite == map.end())
        {
//            缓存满了
            if(cache.size() == size)
            {
//                pair<int,int> lastpair = cache.back();
//                先把缓存清除了
                map.erase(cache.back().first);
                cache.pop_back();
            }
        } else
        {
            cache.erase(map[key]);
        }
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }

private:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(){

    system("pause");
    return 0;
}