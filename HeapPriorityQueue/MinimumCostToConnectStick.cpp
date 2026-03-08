#include "../common.hpp"

/*
You have some number of sticks with positive integer lengths. These lengths are given as an array sticks, where sticks[i] is the length of the iᵗʰ stick.

You can connect any two sticks of lengths x and y into one stick by paying a cost of x + y.

You must connect all the sticks until there is only one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

Thought process:
    To minimize cost, try not to pick and merge the largest stick more often as that going to increase our cost 
    try to pick smallest two sticks everytime 
    use a minheap to always get the two most smallest sticks 
*/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());

        long long cost = 0;
        while(minHeap.size() != 1){
            int s1 = minHeap.top(); minHeap.pop();
            int s2 = minHeap.top(); minHeap.pop();

            int s3 = s1 + s2;
            cost += s3;  minHeap.push(s3);
        }

        return cost;
    }
};

int main(){
    Solution sol;

    vector<int> sticks = {1,8,3,5};

    cout << sol.connectSticks(sticks) << endl;
}