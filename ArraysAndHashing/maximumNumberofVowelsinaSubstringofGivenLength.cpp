#include "../common.hpp"

/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
*/

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};

        int left = 0;
        int vowelCount = 0;
        int maxCount = 0;
        for (int right = 0; right < (int)s.size(); right ++){
            if (vowelSet.contains(s[right])) vowelCount ++;

            if (right - left + 1 > k){
                if (vowelSet.contains(s[left])) vowelCount --;
                left ++;
            }
            maxCount = max(maxCount, vowelCount); 

        }
        return maxCount;
    }
};

int main(){
    Solution sol;
    
    cout << sol.maxVowels("leetcode", 3) << endl; // 2 lee
    cout << sol.maxVowels("aeiou", 2) << endl; // 2
}