#include "../common.hpp"

/*
There are several cards arranged in a row, and each card has an associated number of points. 
The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
1, 2, 3, 4, 5, 6, 1 k = 3
l        
         r               
*/
#include <numeric>
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int left = 0;
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int windowSum = 0;
        int maxScore = 0;
        int windowSize = n - k;
        for (int right = 0; right < n; right ++){
            windowSum += cardPoints[right];

            if (right - left + 1 > windowSize){
                windowSum -= cardPoints[left];
                left ++;
            }

            if (right - left + 1 == windowSize){
                int score = totalSum - windowSum;
                maxScore = max(maxScore, score);
            }
            
        }
        return maxScore;
    }
};