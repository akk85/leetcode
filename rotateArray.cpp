#include "common.hpp"


/*
You are given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Thought process:
    Reverse whole array then reverse first k elements then reverse remaining n - k elements 
Input: nums = [1,2,3,4,5,6,7,8], k = 4

Output: [5,6,7,8,1,2,3,4]

1,2,3,4

5,6,7,8,

*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();  k %= n;

        if (n == 0) return;

        if (k == 0) return;
        reverse(nums, 0, n - 1);

        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    void reverse(vector<int>& nums, int leftPos, int rightPos){
        int left  = leftPos;
        int right = rightPos;

        while (left < right){
            swap(nums[left], nums[right]);
            left  ++;
            right --; 
        }
    }
};

void printResult(vector<int>& result){
    for (const int& num : result){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,4,5,6,7,8};  printResult(nums);

    sol.rotate(nums, 4);  printResult(nums);



}