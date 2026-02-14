#include "common.hpp"

/*
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
Return the number of gifts remaining after k seconds.

intiuion    
    use a max heap and for k times pop top element push back floor of its square root
    return sum of values in heap after end of loop

psuedo code
    heappush(all elements)
    for int i = 0 until i < k
        heappop top elemnt
        heappush(floor squarrrot of top)

    return sum of heap
*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // use a heap
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++){
            int max = maxHeap.top();
            int squareRoot = static_cast<int>(sqrt(max));
            maxHeap.pop();

            maxHeap.push(squareRoot);
        }

        int sum {};
        while (!maxHeap.empty()){
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return sum;
    }
};