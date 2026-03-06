#include "../common.hpp"

/*
Thought process:
    1. perform binary search to find the minimum index
        * with this we can divide the array into two sorted halves 
    2. perform binary search again in respective half to find the target value index
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left  = 0;
        int right = nums.size() - 1;

        // find minimum index
        while (left < right){
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int minIndex = left;
        left  = 0;
        right = nums.size() - 1;
        if (target >= nums[minIndex] && target <= nums[right]){
            left = minIndex;
        } else {
            right = minIndex - 1;
        }

        // find min index
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] < target){
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;

    }

/*
        3,4,5,6,1,2  // 2          
                

        0,1,2,3,4,5,6
        l     m     r 
*/
};

int main(){
    Solution sol;

    vector<int> nums = {3,4,5,6,1,2}; int target = 1;
    cout << sol.search(nums, target) << endl;

    nums = {3,5,6,0,1,2}; target = 4;
    cout << sol.search(nums, target) << endl;

    nums = {4,5,6,7,0,1,2}; target = 0;
    cout << sol.search(nums, target) << endl;

}

/*
        3,4,5,6,1,2           
        l   m     r
              l

        0,1,2,3,4,5,6
        l     m     r 
*/