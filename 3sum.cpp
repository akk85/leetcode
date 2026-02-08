#include "common.hpp"

/*
using two pointers approach
1. iterate over the array element and for each value send out two pointers to seach for the complement 0 - currentvalue
2. also handle duplicates by moving the pointers accordlingly

Timw O(n^2) for each value we iterate over the array twice Space O(1)
*/
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] > 0) break; // all remaining numbers are positive and cannot add up to make zero 
            if (i != 0 and nums[i] == nums[i - 1]) continue;  // avoid searching again if i value is same as the i value we just searched 

            int l = i + 1;
            int r = n - 1;

            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0){
                    l++;
                } else if (sum > 0){
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    
                    while (l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                }
            }
        }

        return res;
    }
};

/*
-4 -1 -1 -1 0 1 2 2 
       i
            l         
              r 
*/

int main(){
    Solution sol;

    vector<int> nums = {-1,0,1,2,-1,-4};
    sol.threeSum(nums);


}