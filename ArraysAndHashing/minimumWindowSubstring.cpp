#include "../common.hpp"

/*
Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) 
is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> stringtwoMap;
        for (const char& c : t) {
            stringtwoMap[c]++;
        }
        
        unordered_map<char, int> windowMap;

        string stringOne = s;
        int need = stringtwoMap.size();
        int have = 0;

        string result;
        int left      = 0;
        int minLength = INT_MAX;
        int resLeft = 0;
        for (int i = 0; i < stringOne.size(); i++){
            char ch = stringOne[i];

            if (stringtwoMap.contains(ch)){
                windowMap[ch]++;
                if (windowMap[ch] == stringtwoMap[ch]) have++;
            }

            while(have == need){
                int currentWindowLength = i - left + 1;
                if (currentWindowLength < minLength){
                    minLength = currentWindowLength;
                    resLeft = left;
                }

                char leftChar = stringOne[left];
                left++;

                if (windowMap.contains(leftChar)){
                    windowMap[leftChar]--;
                    if (windowMap[leftChar] < stringtwoMap[leftChar]) {
                        have--;
                    }
                }
                                
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(resLeft, minLength);
    }
};
/*
t = "ABC"
s = "ADOBECODEBANC", 
               l
                 r
map1 = abc
windowmap = bac

*/