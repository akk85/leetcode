#include "../common.hpp"

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

intuition:
    essentially just looking for an anagram of size s1 in s2
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int>  stringOneCharFreqMap;
        for (const char& ch : s1) stringOneCharFreqMap[ch] ++;

        unordered_map<char, int> windowMap;
        for (int i = 0; i < (int)s1.size(); i ++) windowMap[s2[i]] ++;

        if (windowMap == stringOneCharFreqMap) return true;

        int left = 0;
        for (int right = (int)s1.size(); right < (int)s2.size(); right ++){
            windowMap[s2[right]] ++;
            windowMap[s2[left]] --;
            if (windowMap[s2[left]] == 0) windowMap.erase(s2[left]);
            left ++;

            if (stringOneCharFreqMap == windowMap) return true;
        }

        return false;
    }
};


int main(){
    Solution sol;

    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << boolalpha << sol.checkInclusion(s1, s2) << endl; // true;
}