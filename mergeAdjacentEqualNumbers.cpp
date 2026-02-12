#include "common.hpp"

/*
You are given an integer array nums.

You must repeatedly apply the following merge operation until no more changes can be made:

If any two adjacent elements are equal, choose the leftmost such adjacent pair in the current array and replace them with a single element equal to their sum.
After each merge operation, the array size decreases by 1. Repeat the process on the updated array until no more changes can be made.

Return the final array after all possible merge operations.

pseudo code
    for each curr in array
        while stack and stack.top == curr
            int sum = stack.top + curr
            stack.top
            curr = sum

        stack.push(curr)

    return stack
*/

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> stk;

        for (int& num : nums){
            long long curr = num;
            while (!stk.empty() && stk.back() == curr){
                long long sum = stk.back() + curr;
                stk.pop_back();
                curr = sum;
            }
            stk.push_back(curr);
        }
        return stk;
    }

};

void printResult(const vector<long long>& result){
    for (const long long & val : result){
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    Solution sol;

    vector<int> nums = {3, 1, 2, 2};
    vector<long long> result = sol.mergeAdjacent(nums);  // 3 1 4 
    printResult(result);

    nums = {2,2,4};
    result = sol.mergeAdjacent(nums);  // 8
    printResult(result);

    nums = {3,7,5};
    result = sol.mergeAdjacent(nums);  // 3 7 5
    printResult(result);

    nums = {4,2,2,4};
    result = sol.mergeAdjacent(nums);  // 8 4
    printResult(result);

}