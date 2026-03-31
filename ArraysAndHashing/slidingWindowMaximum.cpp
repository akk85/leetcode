#include "../common.hpp"

/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 

You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

I can use a deque whose front will always store the top element per k window size;

for each element in array we check if its greater than the current elements in dequeu if so 
wr pop all of them since they wont contribute to the next window iteration 
we then push currrent into dequeu

if size of window is now greater than k we pop from front to remove the stale max which is not for this current window
we only pop if the front is off outside window i.e current left since we dont want to pop valid ax for valid current windown
if window is size k we push current max which is front of deque to our resukt array
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

            if (right - left + 1 > k) { // window greater than k move left index and remove from front stale max left values nt supposed to be in this window 
                left++;
                if (dq.front() < left) dq.pop_front();
            }

            if (right - left + 1 == k){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

