#include "../common.hpp"

/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

thought process:
    guaranteed that the values in the edge can be peak due to now taving  neighbors
    we can do a binary search
    checking mid value. if right neighbor is greater than peak we know there is a peak value on the right since either 
    in the rirght a value dips down making a neighbor a peak or the right just keeps on increasing making right most value a peak
    saeme case with the left side:
        if a left neighbor is greater a peak exists in that side since either all values are monotically decreasing until id value making 
        the first value a peak since it has no left neighbor or a certain value dips on the left making a value there a 
        peak

pseudo code
    left = 0; right = n - 1
    while (l < right)
        m = (l + r ) / 2
        if m+ 1 is greater than m 
            shift l to mid + 1
        if m - 1 is greater than m
            shift r to mid - 1
        else m-1 is less than mid and mid + 1 is less than mid making mid a peak
            return mid 
            
            
    Time -> O(log n) due to discarding about half of the array every time
    Space -> O(1) only using constant space with the variable 


*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        // check first and last values if peaks 
        if (nums[l] > nums[l + 1]){
            return l;
        }
        if (nums[r] > nums[r - 1]){
            return r;
        }

        l += 1;
        r -= 1;

        while (l < r){
            int mid = (l + r) / 2;
            if (nums[mid + 1] > nums[mid]){
                l = mid + 1;
            } 
            else if (nums[mid - 1] > nums[mid]){
                r = mid - 1;
            }
            else {
                return mid;
            }
        }

        return l; // case when l < r 
    }
};


int main(){
    Solution sol;

    vector<int> nums = {1,2,3,1};  // value 3 index 2

    cout << sol.findPeakElement(nums) << endl;

    nums = {1,2,1,3,4,5,0};   // value 5 index 5 or veven value 2 index 1 

    cout << sol.findPeakElement(nums) << endl;
}
