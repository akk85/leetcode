#include "common.hpp"

/*
You are given an integer array nums where each element nums[i] indicates your maximum jump length at that position.

Return true if you can reach the last index starting from index 0, or false otherwise.

Thought process:
    start from end of array and see if we can reach it by iterating backwards
        1. make goal = last value
        start iteration at second last value and check if we can reach goal from there if yes
        move goal to this index and repeat until begiining of string
        if succesful goal should be at index 0 else false 


*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        
        
        for (int i = n - 2; i >= 0; i--){
            int jumpWeight = nums[i];
            if (i + jumpWeight >= goal){
                goal = i;
            }
        }

        return goal == 0;
    }
};

/*
[1,2,0,1,0]
|
goal = 1

    
[1,2,1,0,1]|

goal = 1

*/


int main(){
    Solution sol;

    vector<int> nums = {1,2,0,1,0};
    cout << boolalpha << sol.canJump(nums) << endl;

    nums = {1,2,1,0,1};
    cout << boolalpha << sol.canJump(nums) << endl;

    nums = {2,3,1,1,4};
    cout << boolalpha << sol.canJump(nums) << endl;

    nums = {3,2,1,0,4};
    cout << boolalpha << sol.canJump(nums) << endl;
}