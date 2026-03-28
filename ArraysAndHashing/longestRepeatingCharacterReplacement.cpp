#include "../common.hpp"

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Intuition:
    at any time since we want to have a window of only 1 character minimum change would be the letters not same with this
    dominating character 
    eg  A, A, B, C, A if k == 2 dominating is a and change needed is 2 and change is less than or eual that k so this is valid 
    if twas valid we would have to start shrinking from left until we have less or equal than k elements need changing 


    A, A, B, C, A, D k = 2
    l  
                   r
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charFreqWindowMap; //char -> freq in the valid window

        int dominatingFreq = 0;
        int left = 0;
        int maxLength =  0;
        for (int right = 0; right < (int)s.size(); right ++){
            charFreqWindowMap[s[right]] ++;

            dominatingFreq =  max(dominatingFreq, charFreqWindowMap[s[right]]);

            int needChanging = right - left + 1 - dominatingFreq;

            while(needChanging > k){
                charFreqWindowMap[s[left]] --;
                left ++;
                needChanging = (right - left + 1) - dominatingFreq;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main(){
    Solution sol;

    cout << sol.characterReplacement("ABAB", 2) <<    endl; // 4

    cout << sol.characterReplacement("AABABBA", 1) << endl; // 4
}