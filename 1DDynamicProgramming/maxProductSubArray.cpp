#include "../common.hpp"

/*

Given an integer array nums, find a subarray that has the largest product within the array and return it.

A subarray is a contiguous non-empty sequence of elements within an array.

You can assume the output will fit into a 32-bit integer.

Thought Process:
    * for each number keep track of the current max and current min we have seen so far
    * we track current min as this might maximize our product for the case we have a negative current min and then encounter a negative value
    * for each value we get 
            * currmax as the max of currmax * num, currmin * num, num
            * currmin as the min of currmax * num, currmin * num, num
            * we update result with the currmax everytime
    
    pseudo code:
        currMax = 1
        currMin = 1
        for each num in nums:
            prevCurrMax = currMax
            currMax = max(currMax * num, currMin * num, num);
            currMin = min(prevCurrMax * num, currMin * num, num);
            res = max(res, currMax)

        return res
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res     = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < n; i++){
            int num = nums[i];
            int prevCurrMax = currMax;
            currMax = max(max(currMax * num, currMin * num), num);
            currMin = min(min(prevCurrMax * num, currMin * num), num);
            res     = max(res, currMax);
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,4,5};

    cout << sol.maxProduct(nums) << endl;  // 120

    nums = {-2,5,-10};

    cout << sol.maxProduct(nums) << endl;  // 100

    nums = {1,2,-3,4};

    cout << sol.maxProduct(nums) << endl;  // 4

    nums = {-2,0,-1};

    cout << sol.maxProduct(nums) << endl;  // 0
}
