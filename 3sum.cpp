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

            int left = i + 1;
            int right = n - 1;

            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)       left ++;
                else if (sum > 0) right --;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left  ++;
                    right --;
                    
                    while (left < right && nums[left] == nums[left - 1]) left ++;
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
void printResult(vector<vector<int>>& result){
    for (const vector<int>& vec : result){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    Solution sol;

    vector<int> nums = {-4,-1,-1,0,1,2,4}; 
    vector<vector<int>>  result = sol.threeSum(nums);


    printResult(result);

}