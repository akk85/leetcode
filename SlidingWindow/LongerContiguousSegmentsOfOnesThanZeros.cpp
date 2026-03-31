#include "../common.hpp"

/*
Given a binary string s, return true if the longest contiguous segment of 1's is strictly
longer than the longest contiguous segment of 0's in s, or return false otherwise.

For example, in s = "110100010" the longest continuous segment of 1s has length 2, and the longest continuous segment of 0s has length 3.
Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.

1101000110
       l
        r

one = 2
*/

class Solution {
private:
    int findConsecutive(string& s, int value){

        int left = 0;
        int maxLength = 0;
        for (int right = 0; right < s.size(); right ++){
            if (s[right] != value){
                left = right + 1;
                continue;
            }

            int length = right - left + 1;
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
public:
    bool checkZeroOnes(string s) {
        int maxOne   = findConsecutive(s, '1');
        int maxZeros = findConsecutive(s, '0');

        return maxOne > maxZeros;
    }
};