#include "common.hpp"

/*
You are given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

leftsum =  11                    rightsum = 11
             1,7,3,6,5,6.      
                   i

*/

class Solution {
public:
    //Time: O(n) Space: O(1) extra space
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = sum(nums);
        int i = 0;
        while (i < n){
            rightSum = rightSum - nums[i];
            if (leftSum == rightSum){
                return i;
            }
            leftSum = leftSum + nums[i];
            i++;
        }
        return -1;
    }

    int sum(vector<int>& nums){
        int total {};
        for (const int& num : nums){
            total += num;
        }
        return total;
    }
};


int main(){
    Solution sol;

    vector<int> nums = {1,7,3,6,5,6};      // index 3
    cout << sol.pivotIndex(nums) << endl;

    nums = {3,2,1};                      // index -1 
    cout << sol.pivotIndex(nums) << endl; 

    nums = {2,1,-1};                    // index 0
    cout << sol.pivotIndex(nums) << endl;

}