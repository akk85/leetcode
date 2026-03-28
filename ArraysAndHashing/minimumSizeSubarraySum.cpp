#include "../common.hpp"

/*
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum  = 0;
        int left = 0;
        int maxLength = INT_MAX;
        for (int right = 0; right < (int)nums.size(); right ++){
            sum += nums[right];

            while(sum >= target){
                int length = right - left + 1;
                maxLength = min(maxLength, length);

                sum -= nums[left];
                left ++;
            }
        }

        if (maxLength == INT_MAX) return 0;

        return maxLength;
    }
};

/* 
2 3 1 2 4 3
  l
      r 
*/