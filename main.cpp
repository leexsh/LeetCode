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
    TreeNode(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class LFUCache {
public:
    LFUCache(int capacity) {
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


int main() {

    return 0;
}