#include "common.hpp"

/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the array.

You are given two 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2. nums2 contains unique elements.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]

Output: [-1,3,-1]
Explanation:

There is no next greater element for 4.
3 is the next greater element for 1.
There is no next greater element for 2.
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        
    }
    
    void print(vector<int> vec){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
};


int main(){
    Solution sol;
    vector<int> nums1 = {4,1,2}; vector<int> nums2 = {1,3,4,2};

    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    sol.print(res);
}