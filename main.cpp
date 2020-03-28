#include <iostream>
#include <vector>
using namespace std;
//
// Created by leexsh on 2020/3/26.
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(nums.empty())
        {
            return false;
        }
        int mid;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] >= nums[left])
            {
                if(target <= nums[mid] && target >= nums[left])
                {
                    right  = mid - 1;
                } else
                {
                    left = mid + 1;
                }

            } else{
                if(nums[mid] <= target && target <= nums[right])
                {
                    left = mid + 1;
                } else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {

    cout<<endl;

    return 0;
}