#include "../common.hpp"

/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 

You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;

        int left = 0;
        vector<int> ans;
        for (int right = 0; right < nums.size(); right ++){
            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }

            dq.push_back(right);

            if (right - left + 1 > k) { // window greater than k 
                if (dq.front() == left) dq.pop_front();
                left++;
            }

            if (right - left + 1 == k){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

