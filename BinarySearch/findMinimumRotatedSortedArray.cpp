#include "../common.hpp"

/*
You are given an array of length n which was originally sorted in ascending order. It has now been rotated between 1 and n times. For example, the array nums = [1,2,3,4,5,6] might become:

[3,4,5,6,1,2] if it was rotated 4 times.
[1,2,3,4,5,6] if it was rotated 6 times.
Notice that rotating the array 4 times moves the last four elements of the array to the beginning. Rotating the array 6 times produces the original array.

Assuming all elements in the rotated sorted array nums are unique, return the minimum element of this array.

A solution that runs in O(n) time is trivial, can you write an algorithm that runs in O(log n) time?

Thought process:
    we will do a bianry search
    since we know the array was sorted in increasing order before rotating then we know by doing a binary search we
    can find the half where the minimum values is
    eg [1,2,3,4,5,6]
        l   m     r
    * Here if mid value is less than right then our minimum is on left of mid inclusive of mid 
    eg [3,4,5,6,1,2]
        l   m     r
    * Here m is greater than r so our mid is on right of mid 
    eg [4,5,0,1,2,3]
        l   m     r
    * Here mid is less than right so we search in the left side inclusive of mid 
    [4,5,0,1,2,3]
       m 
         r    
         l
*/
class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r){
            int m = (l + r) / 2;
            if (nums[m] > nums[r]){
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }

};


int main(){
    Solution sol;
    vector<int> nums = {3,4,5,6,1,2};

    cout << sol.findMin(nums) << endl;

    nums = {4,5,0,1,2,3};

    cout << sol.findMin(nums) << endl;

    nums = {4,5,6,7};

    cout << sol.findMin(nums) << endl;
}