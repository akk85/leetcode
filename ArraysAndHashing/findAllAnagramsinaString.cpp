#include "../common.hpp"

/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

Intuition:
    use a fixed window of size p and loop across s 
    maintain a map of p's characters and map of current window
    if they match append left index to result
c b a e b a b a c d
  l
      r 
abc
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        unordered_map<char, int> s1map;
        unordered_map<char, int> windowMap;
        for (const char& ch : p) {
            s1map[ch]++; 
        }
        for (int i = 0; (int)i < p.size(); i++) {
            windowMap[s[i]] ++;
        }

        vector<int> ans;
        if (windowMap == s1map) ans.push_back(0);

        int left = 0;
        for (int right = p.size(); right < s.size(); right ++){
            windowMap[s[right]] ++;
            windowMap[s[left]] --;

            if (windowMap[s[left]] == 0) windowMap.erase(s[left]);

            left ++;
            if (windowMap == s1map) ans.push_back(left);

        }

        return ans;
    }
};
