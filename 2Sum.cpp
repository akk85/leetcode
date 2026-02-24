#include "common.hpp"

/*
Given an array of integers nums and an integer target, 
return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.
*/
class Solution {
public:
    // using a map for tracking the difference time O(n) space O(n)
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < static_cast<int>(nums.size()) ; i++){
            int diff = target - nums[i];
            if (seen.count(diff)){
                return {seen[diff], i};
            }
            seen[nums[i]] = i;
        }

        return {-1, -1};
    }


    void print(const vector<int> vec){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
};


int main(){
    Solution sol;

    vector<int> nums = {4,3,5,6}; 

    vector<int> vec = sol.twoSum(nums, 9);
    sol.print(vec);

    vec = sol.twoSum(nums, 3);
    sol.print(vec);
}