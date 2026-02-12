#include "common.hpp"

/*
Given an array nums containing n integers in the range [0, n] without any duplicates, 
return the single number in the range that is missing from nums.

Follow-up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

[1,2,3] -> 0

[0,2] -> 1

*/

class Solution {
public:
    int missingNumberSorting(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int index = 0; index <= n; index++){
            if (nums[index] != index){
                return index;
            }
        }

        return -1;
    }

    int missingNumberSet(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen(nums.begin(),  nums.end());
        for (int num = 0; num <= n; num++){
            if (!seen.contains(num)){
                return num;
            }
        }
        return -1;
    }
/*
0 1 2 3 
1 2 3 


*/
    int missingNumberBitWise(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i <= n; i++){
            x = x ^ i;
        } 
        int y = 0;
        for (int num : nums){
            y = y ^ num;
        }

        return x^y;
    }  
    
    int missingNumberSum(vector<int>& nums){
        int n = nums.size();
        long long sum = {};
        for (const int& num : nums){
            sum += num;
        }

        long long sumNRange = n * (n + 1) / 2;

        return int(sumNRange - sum);
    }

};

int main(){
    Solution sol;

    // TestCase1
    vector<int> nums = {1,2,3};
    cout << sol.missingNumberSorting(nums) << endl;
    cout << sol.missingNumberSet(nums) << endl;
    cout << sol.missingNumberBitWise(nums) << endl;
    cout << sol.missingNumberSum(nums) << endl;


    nums = {0,2};
    cout << sol.missingNumberSorting(nums) << endl;
    cout << sol.missingNumberSet(nums) << endl;
    cout << sol.missingNumberBitWise(nums) << endl;
    cout << sol.missingNumberSum(nums) << endl;
}
