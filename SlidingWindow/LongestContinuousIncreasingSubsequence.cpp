#include "../common.hpp"

/*
Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). 
The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by
two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

1,3,5,4,7
      l
      r
2,2,2,2,2
  l
  r
1,2,3,4,5]
l
        r
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0;

        int maxLength = 1;
        for (int right = 1; right < nums.size() - 1; right ++){
            if (nums[right] > nums[right - 1]){
                int length = right - left + 1;
                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};
