#include "common.hpp"

/*
Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

[1,2]  [-2,-1]   [-1,2]  [0,2]
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map34;

        for (const int& c : nums3){
            for (const int& d : nums4){
                map34[c + d] ++;
            }
        }

        int count = 0;
        for (const int& a : nums1){
            for (const int& b : nums2){
                int diff = 0 - (a + b);
                count += map34[diff];
            }
        }

        return count;
    }
};

int main(){
    Solution sol;

    vector<int> nums1 = {1,  2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0,  2};

    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << endl;  // 2

    nums1 = {0};
    nums2 = {0};
    nums3 = {0};
    nums4 = {0};

    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << endl;  // 1
}

