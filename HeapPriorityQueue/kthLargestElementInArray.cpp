#include "../common.hpp"

/*
Given an unsorted array of integers nums and an integer k, return the kth largest element in the array.

By kth largest element, we mean the kth largest element in the sorted order, not the kth distinct element.

Follow-up: Can you solve it without sorting?

Thought process:
    iterate over all elements in nums pushing num into a min heap
    if min heap size exceeds k pop from the heap
    at end return top element in heap 

    time is O(n) for iteratibg over array 
    each pop and push to heap takes log k and popping and pushing for n elements we get nlogk for all heap operations 
    space is O(n)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const int& num : nums){
            minHeap.push(num);

            if (static_cast<int>(minHeap.size()) > k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,3,1,5,4};

    cout << sol.findKthLargest(nums, 2) << endl;

    nums = {2,3,1,1,5,5,4};

    cout << sol.findKthLargest(nums, 3) << endl; 
}
