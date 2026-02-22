#include "common.hpp"

class Solution{
public:
    int maxSubArrayLength(vector<int>& nums, int k){
        unordered_map<int, int> seen;        
        seen[0] = -1;

        int currSum = 0;
        int maxLength = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            int diff = currSum - k;

            if (seen.contains(diff)){
                int length = i - seen[diff];
                maxLength = max(maxLength, length);
            }

            if (!seen.contains(currSum)){
                seen[currSum] = i;
            }
        }

        return maxLength;
    }
};
/*

nums = [1, -1, 5, -2, 3]    k = 2

currsum = 3

sum  index
0     -1
1      0
5.     2
*/
int main(){
    Solution sol;

    vector<int> nums = {1, -1, 5, -2, 3}; int k = 3;

    cout << sol.maxSubArrayLength(nums, k) << endl;
}