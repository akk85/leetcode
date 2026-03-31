#include "../common.hpp"

/*
Given a binary array nums and an integer k, 
return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

1,1,1,0,0,0,1,1,1,1,0

          l
                   r
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int maxLength = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right ++){
            if (nums[right] == 0){
                zeros += 1;
            }

            while(zeros > k){
                if (nums[left] == 0) {
                    zeros --;
                }
                left ++;
            }

            int length = right - left + 1;
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};
