#include "../common.hpp"

/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) 
Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Thought process:
    find prefix sum for each index
    rangequery(left and right) = prefix[right] - prefix[left - 1]
*/
class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);
        int total = 0;
        for (int i = 0; i < n; i++){
            total += nums[i];
            prefixSum[i] = total;
        }
    }
    
    int sumRange(int left, int right) {
        int rightSum = prefixSum[right];
        int leftSum;
        if (left == 0) leftSum = 0;
        else leftSum = prefixSum[left - 1];

        int rangeSum = rightSum - leftSum;

        return rangeSum;
    }
};