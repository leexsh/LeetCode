#include <bits/stdc++.h>
using namespace std;
//
// Created by leexsh on 2019/3/26.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> pq_max;
    priority_queue<int, vector<int>, less<int>> pq_min;
    MedianFinder() {

    }
    void modify () {
        if (pq_max.size() > pq_min.size() + 1) {
            pq_min.push(pq_max.top());
            pq_max.pop();
        } else if (pq_max.size() < pq_min.size() - 1) {
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
    }
    void addNum(int num) {
        if (pq_max.empty()) {
            pq_max.push(num);
            return;
        }
        if (num <= pq_max.top()) {
            pq_max.push(num);
        } else {
            if (pq_min.empty()) {
                pq_min.push(num);
            }
            if (num < pq_min.top()) {
                pq_max.push(num);
            } else {
                pq_min.push(num);
            }
        }
        modify();
    }

    double findMedian() {
        int min_s = pq_min.size();
        int max_s = pq_max.size();
        if (pq_max.empty() && pq_min.empty()) {
            return 0;
        }
        if (pq_max.empty() && !pq_min.empty()) {
            return pq_min.top();
        }
        if (!pq_max.empty() && pq_min.empty()) {
            return pq_max.top();
        }
        if (((min_s + max_s) & 1) == 0) {
            return (pq_max.top() + pq_min.top()) * 0.5;
        }

        return min_s > max_s ? pq_min.top() : pq_max.top();
    }
};

int main() {
    return 0;
}