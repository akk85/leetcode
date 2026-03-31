#include "../common.hpp"

/*
Given a binary array nums, 
return the maximum number of consecutive 1's in the array if you can flip at most one 0.


[1,0,1,1,0,1]
     l
           r
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLength = 0;
        int left = 0;
        int zeros = 0;
        for (int right = 0; right < nums.size(); right ++){
            if (nums[right] == 0){
                zeros += 1;
            }

            while(zeros > 1){
                if (nums[left] == 0){
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
