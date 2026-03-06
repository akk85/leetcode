#include "../common.hpp"


/*
You are given an integer array nums and an integer val. Your task is to remove all occurrences of val from nums in-place.

After removing all occurrences of val, return the number of remaining elements, say k, such that the first k elements of nums do not contain val.

Note:

The order of the elements which are not equal to val does not matter.
It is not necessary to consider elements beyond the first k positions of the array.
To be accepted, the first k elements of nums must contain only elements not equal to val.
Return k as the final result.

k = 0              val = 1
2,3,4,1,1
      k    
          i 

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (int right = 0; right < static_cast<int>(nums.size()); right++){
            if (nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,2,3,4}; int val = 1;        // 2,3,4           k = 3
    cout << sol.removeElement(nums, val) << endl;

    nums = {0,1,2,2,3,0,4,2}; val = 2;      // 0,1,3,0,4         k = 5
    cout << sol.removeElement(nums, val) << endl;
}