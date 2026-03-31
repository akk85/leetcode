#include "../common.hpp"

/*
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++){
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        unordered_map<int, int> prefixSumIndexMap; // prefixSum -> index
        prefixSumIndexMap[0] = -1;

        int sum = 0;
        int maxLength = 0;
        for (int i = 0; i < (int)nums.size(); i++){
            sum += nums[i];

            if (prefixSumIndexMap.contains(sum)){
                int left = prefixSumIndexMap[sum];
                int length = i - left;

                maxLength = max(maxLength, length);
                continue;
            }
            prefixSumIndexMap[sum] = i;
        }
        return maxLength;
    }
};