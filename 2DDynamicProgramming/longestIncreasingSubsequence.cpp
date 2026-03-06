#include "../common.hpp"

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no 

elements without changing the relative order of the remaining characters.


nums = [9,1,4,2,3,3,7]
 
9 1
1 1
4 1 
2 1
3 1
3 1
7 1

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        for (int i = n - 1; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                if (nums[i] < nums[j]){
                    res[i] = max(res[i], 1 + res[j]);
                }
            }
        }

        return *max_element(res.begin(), res.end());
    }
};

int main(){
    Solution sol;

    vector<int> nums = {9,1,4,2,3,3,7};

    cout << sol.lengthOfLIS(nums) << endl;
}