#include "common.hpp"

/*
Given an array of integers nums and an integer target, 
return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.
*/
class Solution {
public:
    // using two nested for loops time O(n^2) space O(1)
    vector<int> twoSum1(const vector<int>& nums, int target) {
        int n = nums.size(); 
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }

        return {-1,-1};
    }

    // using a map for tracking the difference time O(n) space O(n)
    vector<int> twoSum2(const vector<int>& nums, int target) {
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

    vector<int> nums = {3,4,5,6}; int target = 7;

    vector<int> vec = sol.twoSum1(nums, target);
    sol.print(vec);

    vec = sol.twoSum2(nums, target);
    sol.print(vec);
}