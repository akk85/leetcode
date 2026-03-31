#include "../common.hpp"

/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.
l e e t c o d e
l
    r
abbcccddddeeeeedcba
          l
               r
*/
class Solution {
public:
    int maxPower(string s) {
        int maxLength = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right ++){
            
            if (s[right] != s[left]){
                left = right;
            }

            int length = right - left + 1;

            maxLength = max(maxLength, length);

        }
        return maxLength;
    }
};
