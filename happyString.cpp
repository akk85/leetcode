#include "common.hpp"

/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
You are given three integers a, b, and c, return the longest possible happy string. 

If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".


*/
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        unordered_map<char, int> counter;
        counter['a'] = a; counter['b'] = b; counter['c'] = c;

        priority_queue<pair<int, char>> maxHeap;
        for (const auto& [ch, freq] : counter) {
            if (freq > 0) maxHeap.push({freq, ch});
        }

        string newS;
        while (!maxHeap.empty()){
            auto [freq, ch] = maxHeap.top(); maxHeap.pop();

            int n = newS.size();
            if (n > 1 && newS[n - 1] == ch && newS[n - 2] == ch){
                if (maxHeap.empty()) break;

                auto [freq2, ch2] = maxHeap.top(); maxHeap.pop();
                newS += ch2;

                if (freq2 - 1 > 0) maxHeap.push({freq2 - 1, ch2});
                maxHeap.push({freq, ch});
                
            }
            else {
                newS += ch;
                if (freq - 1 > 0)  maxHeap.push({freq - 1, ch});
            } 
        }

        return newS;

    }
};

int main(){
    Solution sol;

    cout << sol.longestDiverseString(1, 1, 7) << endl; // ccbccacc

    cout << sol.longestDiverseString(0, 1, 5) << endl; // ccbcc

}