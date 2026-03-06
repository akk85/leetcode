#include "../common.hpp"
#include <algorithm>
/*
You are given an array nums of n integers where nums[i] is in the range [1, n], 

return an array of all the integers in the range [1, n] that do not appear in nums.

Note: You can return the integers in any order.
*/
class Solution {
public:
    // using a hashset time overall is O(n) and space is O(1)
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> res;
        for (const int& num : nums){
            seen.insert(num);
        }

        for(int num = 1; num < static_cast<int>(nums.size()) + 1; num++){
            if (!seen.count(num)){
                res.push_back(num);
            }
        }
        return res;
    }
    // Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
    // using linear time O(n) and constant space O(1)
    /*
    idx =  0, 1, 2, 3, 4, 5, 6, 7
    nums = -4,-3,-2,-7, 8, 2, -3,-1
    res = 
    
    */
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1; 
            if (nums[index] > 0){
                nums[index] = -nums[index];
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++){
            if (nums[i] > 0){
                res.push_back(i + 1);
            }
        }
        return res;
    }

    bool contains(vector<int> nums, int target){
        vector<int>::iterator it = find(nums.begin(), nums.end(), target);

        if (it != nums.end()){
            return true;
        }
        return false;
    }

    void print(vector<int> vec){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution sol;   
    vector<int> nums = {4,3,2,7,8,2,3,1};              // 5, 6
    vector<int> res =  sol.findDisappearedNumbers1(nums);
    sol.print(res);
    
    res =  sol.findDisappearedNumbers2(nums);         // 5, 6
    sol.print(res);

    nums = {1,1};
    res = sol.findDisappearedNumbers1(nums);           // 2
    sol.print(res);

    res =  sol.findDisappearedNumbers2(nums);         // 2
    sol.print(res);
}