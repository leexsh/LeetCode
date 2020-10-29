#include <iostream>
#include "vector"
using namespace std;
//
// Created by leexsh on 2020/10/29.
//

// 二分查找 原始版本  有序数组 查找某一个数 返回下标
int binarySearch(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int L = 0;
    int R = nums.size() - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            L = mid + 1;
        } else if (nums[mid] < target) {
            R = mid - 1;
        }
    }
    return  -1;
}

// 二分查找 寻找第一个等于target的值 返回下标
int binarySearch1(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int L = 0;
    int R = nums.size() - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (nums[mid] > target) {
            L = mid + 1;
        } else if (nums[mid] < target) {
            R = mid - 1;
        } else {
            if (mid == 0 || nums[mid - 1] < target) {
                return mid;
            }
            R = mid - 1;
        }
    }
    return -1;
}
// 二分查找 寻找最后一个等于target的值 返回下标
int binarySearch2(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int L = 0;
    int R = nums.size() - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (nums[mid] > target) {
            L = mid + 1;
        } else if (nums[mid] < target) {
            R = mid - 1;
        } else {
            if (mid == 0 || nums[mid + 1] > target) {
                return mid;
            }
            L = mid + 1;
        }
    }
    return -1;
}

// 二分查找 寻找第一个大于等于target的值 返回下标
int binarySearch3(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int L = 0;
    int R = nums.size() - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (nums[mid] >= target) {
            if (mid == 0 || nums[mid-1] < target) {
                return mid;
            }
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    return -1;
}

// 二分查找 寻找最后一个小于等于target的值 返回下标
int binarySearch4(vector<int>& nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int L = 0;
    int R = nums.size() - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (nums[mid] > target) {
            R = mid - 1;
        } else {
            if (mid == nums.size() - 1 || nums[mid + 1 ] > target) {
                return mid;
            }
            L = mid + 1;
        }
    }
    return -1;
}

int main() {


    return 0;
}