#include "../common.hpp"

/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. 
The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
*/


class Solution {
private:
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
        prefixSum.resize(w.size());

        prefixSum[0] = w[0];
        for (int i = 1; i < w.size(); i++){
            prefixSum[i] = prefixSum[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int sum = prefixSum.back();
        int randomNumber = (rand() % sum) + 1;

        int left  = 0;
        int right = prefixSum.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if (prefixSum[mid] >= randomNumber){
                right = mid - 1;
            }
            else if (prefixSum[mid] < randomNumber){
                left = mid + 1;
            }
        }
        return left;
    }
};