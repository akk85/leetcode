#include "../common.hpp"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        size_t l = 1;
        size_t r = 1;

        size_t n = nums.size();

        while (r < n){
            if (nums[r] != nums[r - 1]){
                nums[l] = nums[r];
                l++;
            }
            r++;
        }

        return l;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,10,10,30,30,30};

    cout << sol.removeDuplicates(nums) << endl;
}