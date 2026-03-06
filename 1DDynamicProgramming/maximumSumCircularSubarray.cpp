#include "../common.hpp"

/*
You are given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. 

Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 

Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

[2,3,-4]
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMaxSum = INT_MIN, currSum = 0;
        int globalMinSum = INT_MAX, totalSum = 0;

        // find middle maxSum
        for (const int& num : nums){
            currSum      = max(currSum + num, num);
            globalMaxSum = max(globalMaxSum, currSum);
        }

        // find middle minSum as the maxsum might be sum of edge values excluding middle minSum
        currSum = 0;
        for (const int& num : nums){
            currSum      = min(currSum + num, num);
            globalMinSum = min(globalMinSum, currSum);

            totalSum += num;
        }

        if (globalMaxSum < 0) return globalMaxSum;

        if (globalMaxSum > totalSum - globalMinSum) return globalMaxSum;

        return (totalSum - globalMinSum);

    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,3,-4};

    cout << sol.maxSubarraySumCircular(nums) << endl; // 5

    nums = {-2,4,-5,4,-5,9,4};

    cout << sol.maxSubarraySumCircular(nums) << endl; // 15

    nums = {-2,-3,-1};

    cout << sol.maxSubarraySumCircular(nums) << endl; // -1
}