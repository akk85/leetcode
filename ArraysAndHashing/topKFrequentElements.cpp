#include "../common.hpp"

/*
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Thought process:
    1. build a counter to count the frequency of each value in the nums array
    2. using the frequencies, build a min heap of size k
            * the value with the smallest frequency will always be at the top
            * as we loop over counter , whenever the heap size grows bigger than k, we pop the value at the heap root as we only want to main k elements 
            * we will build the heap using frequencies -> handled automatically by the heap
            * once done iterating over all elements in the counter map, our heap will have the top k frequent elements
    3. go through the min heap and get its alements 

*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numberFrequencyMap;  // num -> freq

        for (const int& num : nums){
            numberFrequencyMap[num] ++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, frequency] : numberFrequencyMap){
            buckets[frequency].push_back(num);
        }
        vector<int> ans;
        for (int i = (int)buckets.size() - 1; i >= 0 && (int)ans.size() < k; i --){
            for (const int& num : buckets[i]){
                if ((int)ans.size() == k) break;
                ans.push_back(num);
            }
        }
        
        return ans;

    }

    void print(const vector<int>& vec){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,2,3,3,3}; int k = 2; // [2,3]
    vector<int> res = sol.topKFrequent(nums, k);

    sol.print(res);
    
    nums = {1,2,2,3,3,3,4,4,4,4}; k = 2; // [3,4]
    res = sol.topKFrequent(nums, k);

    sol.print(res);

    nums = {1 ,2}; k = 2;  // [1,2]
    res = sol.topKFrequent(nums, k);

    sol.print(res);
    /*
    1 - 1
    2 - 1
    */


}