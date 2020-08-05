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
        auto ite = map.find(key);
        if(ite == map.end()){
            return -1;
        }
        auto kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int value) {
        auto ite = map.find(key);
        if(ite == map.end()){
            if(cache.size() == size)
            {

                map.erase(cache.back().first);
                cache.pop_back();
            }
        } else{
            cache.erase(map[key]);
        }
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }

private:
    int size;
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


class LRUCache1 {
public:
    LRUCache1(int capacity) {
        this->size = capacity;
    }

    int get(int key) {
        if (map.find(key) != map.end()){
            int res = (*map[key]).second;
            cache.erase(map[key]);
            cache.push_front(make_pair(key, res));
            map[key] = cache.begin();
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            if (cache.size() == size) {
                map.erase(cache.front().first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();

        }
    }

private:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache2 {
public:
    LRUCache2(int capacity) {
        this->size = capacity;
    }

    int get(int key) {
        if (map.find(key) != map.end()) {
            int res = (*map[key]).second;
            cache.erase(map[key]);
            cache.push_front(make_pair(key, res));
            map[key] = cache.begin();
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            if (size == cache.size()) {
                map.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }

private:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};
int main(){

    system("pause");
    return 0;
}