#include "../common.hpp"

/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and 
each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, 
excluding the space needed to store the output

Intuition:
    since we cant use extra space like a set, we can modify the input array itself
    for each value index = value go to this index and negate the value there as negative
    when we run again into this number and try to negate the value in that index we will find its already negative and we 
    will know that we have seen it before

    caviets
        * -negative indexing so we use abs of that value incase we already negated it
        * add abs value to vector array not the negative one
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i ++){
            
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) ans.push_back(abs(nums[i]));
            nums[index] = -nums[index];
        }
        return ans;
    }
};
