#include "../common.hpp"

/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. 

This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously 

returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.

int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int maxSize;
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for (const int& num : nums){
            minHeap.push(num);

            if (minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > maxSize) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

int main(){
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};

    KthLargest system(k, nums);

    cout << system.add(3) << endl;  // 4
    cout << system.add(5) << endl;  // 5
    cout << system.add(10) << endl; // 5
    cout << system.add(9) << endl;  // 8
    cout << system.add(4) << endl;  // 8
}
/*
k = 3

10 9 8 5 5 4 4 3 2 
*/