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

class Solution {
public:
    int getOne(int num) {
        int res = 0;
        while (num) {
            res++;
            num >>= 1;
        }
        return res;
    }
    int findComplement(int num) {
        int cnt = getOne(num);
        return num ^ ((long)(1 << cnt) - 1);
    }
};

int main(){
    Solution s;
    cout<<s.getOne(5)<<endl;
    return 0;
}