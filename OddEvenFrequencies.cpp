#include "common.hpp"

/*
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.
*/


class Solution {
public:
    // using a hashmap time O(n) and space is O(n);
    int maxDifference1(string s) {
        unordered_map<char, int> counter;
        for (const char& ch : s){
            counter[ch] ++;
        }

        int maxOdd  = INT_MIN;
        int minEven = INT_MAX;
        for (const auto& pair : counter){
            // if odd update maximum odd
            int freq = pair.second;
            if ((freq % 2) == 1){
                maxOdd = max(maxOdd, freq);
            }
            // if even update minimum odd;
            else {
                minEven = min(minEven, freq);
            }
        }

        return maxOdd - minEven;
    }

    // same line of thought but instead of hashmap we can use a fixed size vector/array of 26 char
    int maxDifference2(string s) {
        vector<int> counter(26, 0);

        for (const char& c : s){
            counter[c - 'a'] ++; 
        }
        
        int maxOdd  = INT_MIN;
        int minEven = INT_MAX;

        for (int i = 0; i < static_cast<int>(counter.size()); i++){
            if (counter[i] == 0) continue;
            
            bool isOdd  = (counter[i] % 2 == 1);
            bool isEven = (counter[i] % 2 == 0);

            if (isOdd){
                maxOdd  = max(maxOdd,  counter[i]);
            }
            if (isEven){
                minEven = min(minEven, counter[i]);
            }
        }

        return maxOdd - minEven;
    }
};


int main(){
    Solution sol;

    string s = "aaaaabbc";      // odd - even 
    cout << sol.maxDifference1(s) << endl;
    cout << sol.maxDifference2(s) << endl;

    s = "abcabcab";
    cout << sol.maxDifference1(s) << endl;
    cout << sol.maxDifference2(s) << endl;
}