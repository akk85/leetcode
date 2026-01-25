#include "common.hpp"

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times in the array. 

You may assume that the majority element always exists in the array.
*/

class Solution {
public:
    // using hashmap time O(n) and O(n) space
    int majorityElement1(vector<int>& nums) {
        unordered_map<int, int> counter;

        for (const int& num : nums){
            counter[num] ++;
        }

        int maxCount = {};
        int majority {};
        for (const auto pair : counter){
            int num = pair.first;
            int freq = pair.second;
            if (freq > maxCount){
                maxCount = freq;
                majority = num;
            }
        }

        return majority;
    }

    // using 0(nlogn) time and O(1) or O(1) depennding on the sorting algorithm;
    // sort the array and since the element appears more than n/2 times regardless of where it's block start, 
    // it will always occupy the middle index
    int majorityElement2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }

    // Boyer-Moore Voting Algorithm O(n) time and O(1) time works because since majorty appears more than n/2 it cannot be cancelled out 
    // candidate = 5
    // num = 5
    // count = 0
    // 5,5,1,1,1,5,1
    // 
    int majorityElement3(vector<int>& nums){
        int candidate {};
        int count {};
        for (const int& num : nums){
            if (count == 0){
                candidate = num;
            }
            if (num == candidate){
                count ++;
            } else {
                count --;
            }
        }
        return candidate;
    }

};


int main(){
    Solution sol;
    vector<int> nums = {5,5,1,1,1,5,5};  // 5

    cout << sol.majorityElement1(nums) << endl;
    cout << sol.majorityElement2(nums) << endl;
    cout << sol.majorityElement3(nums) << endl;

    nums = {2,2,2};                      // 2
    cout << sol.majorityElement1(nums) << endl;
    cout << sol.majorityElement2(nums) << endl;
    cout << sol.majorityElement3(nums) << endl;

}