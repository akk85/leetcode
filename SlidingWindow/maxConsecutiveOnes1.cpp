#include "../common.hpp"

/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
1,1,0,1,1,1
      l
          r
*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < nums.size(); right ++){
            if (nums[right] != 1){
                left = right + 1;
            }
            int length = right - left + 1;
            maxLength = max(maxLength, length); 
        }

        return maxLength;
    }
};
