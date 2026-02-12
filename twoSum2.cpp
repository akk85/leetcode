#include "common.hpp"

/*
Thougth process:
    maintain two pointers left and right if nums[left] + nums[right] is less than target shift left to get a bigger
    value.
    if sum is greater shift right to get smaller value
    otherwise return the two index incremented by one as nums array is one indexed 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left  = {};
        int right = numbers.size() - 1;

        while (left < right){ // strictly less as we cant use same number twice
            int sum = numbers[left] + numbers[right];
            if (sum < target){
                left++;
            } else if (sum > target){
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }
        return {-1,-1}; // we never reach here
    }

    void printResult(vector<int>& result){
        for (const int& num : result){
            cout << num << " ";
        }
        cout << endl;
    }
};

int main (){
    Solution sol;

    vector<int> numbers = {1,2,3,4}; int target = 3;

    vector<int> result = sol.twoSum(numbers, target);

    sol.printResult(result);
}
