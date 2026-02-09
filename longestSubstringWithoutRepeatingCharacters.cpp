#include "common.hpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int l = 0;
        int r = 0;
        int n = s.size();
        int longest {};
        while (r < n){
            if (!seen.contains(s[r])){
                seen.insert(s[r]);
                longest = max(longest, r - l + 1);
                r++;
            } 
            while (seen.contains(s[r])){
                seen.erase(s[l]);
                l++;
            }

        }

        return longest;
    }
};

int main(){
    Solution sol;

    string s = "zxyzxyz";
    cout << sol.lengthOfLongestSubstring(s) << endl; // 3

    s = "xxxx";
    cout << sol.lengthOfLongestSubstring(s) << endl; // 1
}

