#include "../common.hpp"

/*
You are given a binary array nums, return the maximum number of consecutive 1's in the array.

maxsofar = 2
count = 3
        1,1,0,1,1,1

*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxSoFar {};
        int count    {};
        for (const int& num: nums){
            if (num == 1){
                count ++;
            } else {
                maxSoFar = max(maxSoFar, count);
                count = 0;
            }
        }
        return max(maxSoFar, count);
    }
};


int main(){

    Solution sol; 
    vector<int> nums = {1,1,0,1,1,1}; //3
    cout << sol.findMaxConsecutiveOnes(nums) << endl;

    nums = {1,0,1,1,0,1}; // 2
    cout << sol.findMaxConsecutiveOnes(nums) << endl;


}