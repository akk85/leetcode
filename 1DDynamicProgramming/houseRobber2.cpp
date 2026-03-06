#include "../common.hpp"

/*
You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a circle, i.e. the first house and the last house are neighbors.

You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.

Return the maximum amount of money you can rob without alerting the police.

Intuition:
    To find max money to rob we just need to make a decision whether to rob the first house or the last house as we cant do both
    1. without factoring that first and house are connected the intiuion is  as below
                to rob a house we actually need to make two decisions either rob or not rob
                to rob meaning add n - 2 neighbor + curr house 
                to not rob means carry forward what n - 1 neighbor had 
                meaing it all comes to do whats the maximum btwn rob so i - 2 nei and i house vs i - 1 neihbor
                we can use a hashmap to just keep track of the previous houses and make decision from that

    2. factoring in the circleness we can run algorithm 1 from first house to second last house
    then run the same algorithm from house second to last and return the max btwn the two scenarios 

*/

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> vec1(nums.begin(), nums.end() - 1);
        vector<int> vec2(nums.begin() + 1, nums.end());

        int firstHouse = dp(vec1);
        int lastHouse  = dp(vec2);

        return max(firstHouse, lastHouse);
    }

    int dp(vector<int>& vec){
        int n = vec.size();
        unordered_map<int, int> house;
        house[0] = vec[0];
        house[1] = max(vec[0], vec[1]);

        for (int i = 2; i < n; i++){
            int rob    = house[i - 2] + vec[i];
            int notRob = house[i - 1];
            house[i]   = max(rob, notRob);
        }

        return house[n - 1];
    }
};

int main(){
    Solution sol;
    
    vector<int> nums = {3,4,3}; // 4
    cout << sol.rob(nums) << endl;

    nums = {2,9,8,3,6};    // 15
    cout << sol.rob(nums) << endl;

    nums = {2,3,2};    // 3
    cout << sol.rob(nums) << endl;   

    nums = {1,2,3,1};    // 4
    cout << sol.rob(nums) << endl;

    nums = {1,5};    // 5
    cout << sol.rob(nums) << endl;

}
