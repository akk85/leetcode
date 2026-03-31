#include "../common.hpp"

/*
Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

a b b c c c a a 
l 
r
*/

class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        int left = 0;
        int ans = 0;
        for (int right = 1; right < s.size(); right ++){
            if (s[right] != s[right - 1]){ // sequence end 
                int n = right - left + 1;

                int count = n * (n + 1) / 2;
                ans   = (ans + count) % MOD;
            }
        }

        return ans;
    }
};

