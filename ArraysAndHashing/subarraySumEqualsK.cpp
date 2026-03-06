#include "../common.hpp"

/*
You are given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

pseudo code
    for each value in array
        find currsum - k
        if difference in hashmap res += frequency of difference
        update hashmap with currsum
    
    return res
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;

        hashMap[0] = 1;
        int currSum = 0;
        int res = 0;
        for (const int num : nums){
            currSum += num;
            int diff = currSum - k;
            if (hashMap.contains(diff)) {
                int freq = hashMap[diff];
                res += freq;
            }

            hashMap[currSum] ++;
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2, -1, 1, 2};

    cout << sol.subarraySum(nums, 2) << endl; //4
}