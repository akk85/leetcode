#include "../common.hpp"
#include <climits>
/*
Given an array of integers nums, find the subarray with the largest sum and return the sum.

A subarray is a contiguous non-empty sequence of elements within an array.

intution very simple
    have a running maxSum 
    have currSum
    for each value in array
        currsum = max of currsum and currsum + value 
        maxValue = max of currsum and maxvalue

    return maxSum

* since array can have negative elements we can initialize maxsum  and cursum with -inf or -int max as range of nums[i] is -104 <= nums[i] <= 104
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; // incase nums is of size 0 
        int curSum = 0;

        for (const int& num : nums){
            curSum = max(curSum + num, num);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};

/*
max = -1
cur = -1

-2 -3 -1
       |


*/

int main(){
    Solution sol;

    vector<int> nums = {2,-3,4,-2,2,1,-1,4};  // 8
    cout << sol.maxSubArray(nums) << endl;

    nums = {-1};  // -1
    cout << sol.maxSubArray(nums) << endl;

    nums = {-2,1,-3,4,-1,2,1,-5,4}; //6
    cout << sol.maxSubArray(nums) << endl;

    nums = {5,4,-1,7,8};  //23
    cout << sol.maxSubArray(nums) << endl;
}