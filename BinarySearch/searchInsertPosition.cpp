#include "../common.hpp"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int res = n;

        int l = 0; int r = n - 1;

        while (l <= r){
            int m = (l + r) / 2;

            if (nums[m] == target){
                return m;
            } 
            else if (nums[m] > target){
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {-1,0,2,4,6,8};

    cout << sol.searchInsert(nums, 5) << endl;
}