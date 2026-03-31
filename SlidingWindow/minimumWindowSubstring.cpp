#include "../common.hpp"

/*
Given two strings s and t, return the shortest substring of s that contains every character in t
(including duplicates). If no such substring exists, return "".

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

ADOBECODEBANC      ABC 
l
     r   
keep a hashmap of chars of string2
use a growing sliding window add char to window  and also have a map for this window too
use two ints for number of unique elements in string 2 and window call them needed and have
for each character if in string2 increment count of have
when window has exactly than needed characters start removing from left while window is still valid and update minlength

*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> stringtwoCharFreqMap;
        for (const char& ch: t){
            stringtwoCharFreqMap[ch] ++;
        }

        int needed = stringtwoCharFreqMap.size();
        int have = 0;

        unordered_map<char, int> windowCharFreqMap;
        int left = 0;
        int minLength = INT_MAX;
        int startPosition = 0;
        for (int right = 0; right < (int)s.size(); right ++){
            
            if (stringtwoCharFreqMap.contains(s[right])){
                windowCharFreqMap[s[right]]++;

                if (windowCharFreqMap[s[right]] == stringtwoCharFreqMap[s[right]]){
                    have += 1;
                }

                while(have == needed){
                    int currWindowLength = right - left + 1;
                    if (currWindowLength < minLength){
                        minLength = currWindowLength;
                        startPosition = left;
                    }

                    if (stringtwoCharFreqMap.contains(s[left])){
                        windowCharFreqMap[s[left]] --;

                        if (windowCharFreqMap[s[left]] < stringtwoCharFreqMap[s[left]]){
                            have --;
                        }
                    }
                    left ++;
                }
            }
        }
        if (minLength == INT_MAX){
            return "";
        }
        string ans = s.substr(startPosition, minLength);

        return ans;
    }
};

int main(){
    Solution sol;

    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl; // BANC


}