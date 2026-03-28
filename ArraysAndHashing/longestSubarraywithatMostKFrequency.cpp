#include "../common.hpp"

/*
Given an integer array nums and integer k, return the length of the longest subarray where every element appears at most k times.
*/


class Solution{
public:
    int longestSubarray(const vector<int>& nums, int k){
        unordered_map<int, int> valueFrequencyMap;

        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < (int)nums.size(); right ++){
            valueFrequencyMap[nums[right]] ++;

            while(valueFrequencyMap[nums[right]] > k){
                valueFrequencyMap[nums[left]] --;
                left ++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,1,2,3,1,2};

    cout << sol.longestSubarray(nums, 2) << endl; // 6

    nums = {1,2,1,2,1,2,1,2};
    cout << sol.longestSubarray(nums, 1) << endl; // 2

    nums = {5,5,5,5,5,5,5};
    cout << sol.longestSubarray(nums, 4) << endl; // 4
}
