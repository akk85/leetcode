#include "../common.hpp"

/*
Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Thought process:
    1. build a counter to count the frequency of each value in the nums array
    2. using the frequencies, build a min heap of size k
            * the value with the smallest frequency will always be at the top
            * as we loop over counter , whenever the heap size grows bigger than k, we pop the value at the heap root as we only want to main k elements 
            * we will build the heap using frequencies -> handled automatically by the heap
            * once done iterating over all elements in the counter map, our heap will have the top k frequent elements
    3. go through the min heap and get its alements 

*/
class Solution{
public:
    vector<int> topKFrequent(const vector<int>& nums, int k){
        unordered_map<int, int> counter;
        for (const int& num : nums){
            counter[num] ++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (const auto& entry : counter){
            int value = entry.first;
            int freq  = entry.second;

            heap.push({freq, value});
            if (static_cast<int>(heap.size()) > k){
                heap.pop();
            }
        }

        vector<int> result;

        while (!heap.empty()){
            result.push_back(heap.top().second);
            heap.pop();
        }

        return result;
    } 

    void print(const vector<int>& vec){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,2,3,3,3}; int k = 2; // [2,3]
    vector<int> res = sol.topKFrequent(nums, k);

    sol.print(res);
    
    nums = {1,2,2,3,3,3,4,4,4,4}; k = 2; // [3,4]
    res = sol.topKFrequent(nums, k);

    sol.print(res);

    nums = {1 ,2}; k = 2;  // [1,2]
    res = sol.topKFrequent(nums, k);

    sol.print(res);
    /*
    1 - 1
    2 - 1
    */

    /*  
        wanted to use pen and paper 
        no need for a seen set 
        he asked me how to pop from a queue
        asked to go search for queue snytax which is very trivial must know syntax
        asked how to append to a queue

        ended up using extra space instead of his approach 

    bugs:
        indexing a node variable
        iterative over a node ?? 

    problem solving 


    problem 2
        misundersntood the question and went the wrong path
        definitly reading from somewhere 

        
        doesnt understand complexities for sorting / heap operations etc 
        doesnt do a dry run step by step he assumes his code works 

    */

}