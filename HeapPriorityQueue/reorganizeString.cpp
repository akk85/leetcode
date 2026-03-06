#include "../common.hpp"


/*
You are given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

You can return any possible rearrangement of s or return "" if not posssible.

Intution:
    use a maxheap to build new string using top element with maxHeap
    to avoid adjacent char of same char for a char that has dominant freq use a prev variable to push it back after one iteration
*/
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counter; // char -> freq
        for (const char& ch : s) counter[ch] ++;

        priority_queue<pair<int, char>> maxHeap;
        for (auto [ch, freq] : counter) maxHeap.push({freq, ch});

        pair<int, char> prev = {0, 'n'};  // temp prev 
        string newS;
        while (!maxHeap.empty()){
            auto [freq, ch] = maxHeap.top(); maxHeap.pop();
            newS += ch;

            if (prev.first > 0) maxHeap.push(prev);
            prev = {freq - 1, ch};
        }

        if (newS.size() != s.size()) return "";
        return newS;
    }
};

int main(){
    Solution sol;

    string s = "axyy";
    cout << sol.reorganizeString(s) << endl;

    s = "abbccdd";
    cout << sol.reorganizeString(s) << endl;

    s = "ccccd";
    cout << sol.reorganizeString(s) << endl; // ""
}