#include "common.hpp"

/*
Given an array of positive integers nums and a positive integer target,

return the minimal length of a subarray whose sum is greater than or equal to target. 

If there is no such subarray, return 0 instead.

Sliding window 
*/
class Solution {
public:
    int minSubArrayLen(vector<int>& nums, int target) {
        int l = 0; int r = 0; int n = nums.size(); int total = 0;

        int res = INT_MAX;
        while (r < n){
            total += nums[r];

            while (total >= target){
                res = min(res, r - l + 1);
                total -= nums[l];
                l += 1;
            }
            r++;
        }

        if (res == INT_MAX) return 0;

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,1,5,1,5,3};

    cout << sol.minSubArrayLen(nums, 10) << endl; // 3
}