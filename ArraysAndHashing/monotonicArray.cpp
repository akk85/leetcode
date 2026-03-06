#include "../common.hpp"

/*
Thought process:
    set two flags to true and when we iterate the list if the condition is not followed flip the condition
*/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true;
        bool isDecreasing = true;

        int n = nums.size();

        for (int i = 1; i < n; i++){
            if (nums[i] > nums[i - 1]){
                isDecreasing = false;
            }
            if (nums[i] < nums[i - 1]){
                isIncreasing = false;
            }
        }

        return isIncreasing || isDecreasing;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,2,3};
    cout << boolalpha << sol.isMonotonic(nums) << endl;

    nums = {6,5,4,4};
    //            i 
    cout << boolalpha << sol.isMonotonic(nums) << endl;

    nums = {1,3,2};
    //          i 
    cout << boolalpha << sol.isMonotonic(nums) << endl;

    nums = {2,2,2,2};
    //        i 
    cout << boolalpha << sol.isMonotonic(nums) << endl;

    nums = {2,3,4,2};
    //        i 
    cout << boolalpha << sol.isMonotonic(nums) << endl;

}