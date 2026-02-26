#include "common.hpp"


/*
You are given five integer arrays: A, B, C, D, and E.

All arrays are non-empty and may contain duplicate and/or negative values.

Your task is to determine whether there exist exactly one element from each array such that their sum equals a given target value.

In other words, return true if there exist indices i, j, k, l, m such that:
text
*/

class Solution { 
public: 
    bool fiveSumExists(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4, vector<int>& nums5){

        unordered_map<int, int> map23;
        unordered_map<int, int> map45;

        for (const int& b : nums2){
            for (const int& c : nums3){
                map23[b + c] ++;
            }
        }

        for (const int& d : nums4){
            for (const int& e : nums5){
                map45[d + e] ++;
            }
        }

        for (const int& a : nums1){
            for (const auto [bc , freq] : map23){
                int diff = 2018 - (a + bc);
                if (map45.contains(diff)) return true;
            }
        }

        return false; 
    } 
};

int main(){
    Solution sol;

    vector<int> nums1 = {1000}, nums2 = {500}, nums3 = {300}, nums4 = {200}, nums5 = {18}; 

    cout << boolalpha << sol.fiveSumExists(nums1, nums2, nums3, nums4, nums5) << endl;

    nums1 = {600, 900, 1200}, nums2 = {300, 400, 500}, nums3 = {200, 250, 300}, nums4 = {100, 150, 180}, nums5 = {268, 318, 338};

    cout << boolalpha << sol.fiveSumExists(nums1, nums2, nums3, nums4, nums5) << endl;

}