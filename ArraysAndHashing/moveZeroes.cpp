#include "../common.hpp"

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left  = 0;

        for (int right = 0; right < (int)nums.size(); right ++){
            if (nums[right] == 0) continue;

            while (left < right && nums[left] != 0) left++;

            swap(nums[left], nums[right]); left ++;
        }
    }
};

int main(){
    Solution sol;

    vector<int> nums = {0,1,0,3,12};
    for (const int& num : nums){
        cout << num << " ";
    }
    cout << '\n';

    sol.moveZeroes(nums);
    for (const int& num : nums){
        cout << num << " ";
    }
    cout << '\n';
}