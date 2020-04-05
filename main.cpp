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

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
};


int main() {
    string s = "babad";
    string str = longestPalindrome(s);
    cout<<str<<endl;

    return 0;
}