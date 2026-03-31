#include "../common.hpp"

/*
You are given an integer array nums and an integer x. In one operation, you can either 
remove the leftmost or the rightmost element from the array nums and subtract its value from x.
Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
sum = 30
target = 20
3,2,20,1,1,3
    l
    r

*/
#include <numeric>
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (x > totalSum) {
            return -1;
        }


        int n = nums.size();
        int targetSum = totalSum - x;
        int sum = 0;
        int left = 0;
        int minOuterWindow = INT_MAX;
        for (int right = 0; right < nums.size(); right ++){
            sum += nums[right];
            

            while(sum > targetSum){
                sum -= nums[left];
                left ++;
            }

            if (sum == targetSum){
                int windowLength = right - left + 1;
                int outerWindow  = n - windowLength;
                minOuterWindow = min(minOuterWindow, outerWindow);
            }
        }

        if (minOuterWindow == INT_MAX){
            return -1;
        }
        return minOuterWindow;
    }
};
