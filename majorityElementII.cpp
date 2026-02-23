#include "common.hpp"

/*
You are given an integer array nums of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 

You can return the result in any order.

Could you solve the problem in linear time and in O(1) space?

Thought process:
    5,2,3,2,2,2,2,5,5,5,1 
    
    2 

10 / 3 = 3 
5 2 
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        int candidate1 = INT_MIN, count1 = 0;
        int candidate2 = INT_MAX, count2 = 0;

        for(const int& num : nums){
            if      (num == candidate1) count1++;
            else if (num == candidate2) count2++;
            else if (count1 == 0) {candidate1 = num; count1 = 1;}
            else if (count2 == 0) {candidate2 = num; count2 = 1;}
            else    {count1 --; count2--;}
        }

        // validate candidates via true counts 

        count1 = 0; count2 = 0;
        for (const int& num : nums){
            if (num == candidate1) count1 ++;
            if (num == candidate2) count2 ++;
        }


        if (count1 > n / 3) result.push_back(candidate1);
        if (count2 > n / 3) result.push_back(candidate2);

        return result;
    }
};

void printResult(const vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<int> nums = {5,2,3,2,2,2,2,5,5,5};

    vector<int> result = sol.majorityElement(nums);

    printResult(result);
}



