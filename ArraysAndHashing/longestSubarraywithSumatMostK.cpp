#include "../common.hpp"

/*

Given an array of positive integers nums and integer k, return the length of the 
longest subarray whose sum is less than or equal to k.
*/


class Solution{
public:
    int longestSubarray(const vector<int>& nums, int k){
        int sum = 0;
        int longestLength = 0;
        int left = 0;
        for (int right = 0; right < (int)nums.size(); right ++){
            sum += nums[right];

            while(sum > k){
                sum -= nums[left];
                left ++;
            }

            longestLength = max(longestLength, right - left + 1);
        }

        return longestLength;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,1,5,1,3,2};
    cout << sol.longestSubarray(nums, 7) << endl; // 3
}
