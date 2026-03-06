#include "../common.hpp"

/*
You are given an array of integers stones where stones[i] represents the weight of the ith stone.

We want to run a simulation on the stones as follows:

At each step we choose the two heaviest stones, with weight x and y and smash them togethers
If x == y, both stones are destroyed
If x < y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
Continue the simulation until there is no more than one stone remaining.

Return the weight of the last remaining stone or return 0 if none remain.

use a max heap where the max element is at the top

while the heap length > 1
    pop two heavy stones
    get diff
    if diff > 0 push diff back to heap

return heap top
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();

            int diff = abs(stone1 - stone2);

            if (diff > 0) maxHeap.push(diff);
        }

        return maxHeap.top();
    }
};

int main(){
    Solution sol;

    vector<int> stones = {2,3,6,2,4};

    cout << sol.lastStoneWeight(stones) << endl; // 1
}
