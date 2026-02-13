#include "common.hpp"

/*
You are given an integer array nums where nums[i] represents the amount of money the ith house has. 

The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.

You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.

Return the maximum amount of money you can rob without alerting the police.

thought process
    to rob a house we actually need to make two decisions either rob or not rob
    to rob meaning add n - 2 neighbor + curr house 
    to not rob means carry forward what n - 1 neighbor had 
    meaing it all comes to do whats the maximum btwn rob so i - 2 nei and i house vs i - 1 neihbor
    we can use a hashmap to just keep track of the previous houses and make decision from that

pseudo code
    int n = nums.size();

    map[0] = nums[0]
    map[1] = max(nums[0] , nums[1])

    for (int i = 2; i < n; i++)
        rob = house[i-2] + nums[i]
        notRob = house[i-1]
        map[i] = max(rob, notRob)
        
    return map[n - 1]
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        unordered_map<int, int> house;
        house[0] = nums[0];
        house[1] = max(nums[0], nums[1]);


        for (int i = 2; i < n; i++){
            int rob    = house[i - 2] + nums[i];
            int notRob = house[i - 1];

            house[i] = max(rob, notRob);
        }

        return house[n - 1];
    }
};

int main(){
    Solution sol;
    
    vector<int> nums = {1,1,3,3}; // 4
    cout << sol.rob(nums) << endl;

    nums = {1,2,3,1};    // 4
    cout << sol.rob(nums) << endl;

    nums = {2,9,8,3,6};     // 16 
    cout << sol.rob(nums) << endl;

    nums = {2,7,9,3,1};    // 12
    cout << sol.rob(nums) << endl;

    nums = {1, 100, 1, 1, 100};
    cout << sol.rob(nums) << endl;
}
