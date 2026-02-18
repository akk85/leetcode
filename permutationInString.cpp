#include "common.hpp"

/*
You are given two strings s1 and s2.

Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a substring of s2, then return true.

Both strings only contain lowercase letters.

Thought process:
    1. use two hashmaps of size s1.size
    2. use a sliding window of size s1.size to iterate over characters in that window and put them in a map and check if that map is equal 
    to 1st map of 2nd map.
    3. return true if map are same
    4. return false if we reach to end of string s2 without returning true

    pseudo code
    map1 = s1
    map2 = s2(0: s1.size - 1)
    l = 0 
    r = s1 size - 1

    while r < s2.size
        if (map1 == map2) return true
        map2.remove(left)
        map2.insert(right++)
        l = l++
        r = r++

    return false

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        // Build map1
        for (const char& ch : s1){
            map1[ch] ++;
        }

        // Build map2 of size s1
        int n = s1.size();
        for (int i = 0; i < n; i++){
            char ch = s2[i];
            map2[ch] ++;
        }

        int l = 0;
        int r = n - 1;
        
        int length = s2.size();
        while (r + 1 < length){
            if (map1 == map2) return true;

            char left  = s2[l];
            char right = s2[r + 1];

            map2[left] --;
            if (map2[left]  == 0) map2.erase(left);

            map2[right] ++;

            l += 1;
            r += 1;
        }
        return map1 == map2;
    }
};

int main(){
    Solution sol;

    string s1 = "abc";
    string s2 = "lecabee";

    cout << boolalpha << sol.checkInclusion(s1, s2) << endl;
}
