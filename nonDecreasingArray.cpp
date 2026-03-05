#include "common.hpp"

/*
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        int n = nums.size();

        for (int i = 0; i < n; i++){
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            if (changed) {
                return false;
            }
            
            // 3 4 2 
            if (i == 0 || nums[i + 1] >= nums[i - 1]){
                nums[i] = nums[i + 1];
            }
            else {
                nums[i + 1] = nums[i];
            }

            changed = true;

        }

        return true;
    }
};

