#include "../common.hpp"

/*
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

A substring is a contiguous non-empty sequence of characters within a string.
*/


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> windowCharFreq;
        int left = 0;
        int maxLenght= 0;
        for (int right = 0; right < (int)s.size(); right ++){
            windowCharFreq[s[right]] ++;
            while((int)windowCharFreq.size() > k){
                windowCharFreq[s[left]] --;
                if (windowCharFreq[s[left]] == 0) windowCharFreq.erase(s[left]);
                left ++;
            }

            int length = right - left + 1;
            maxLenght = max(maxLenght, length);
        }
        return maxLenght;
    }
};

int main(){
    Solution sol;

    string s = "eceba"; int k = 2;

    cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl; // 2;
}
