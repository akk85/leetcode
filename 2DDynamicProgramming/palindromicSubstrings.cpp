#include "../common.hpp"

/*
Given a string s, return the number of substrings within s that are palindromes.

A palindrome is a string that reads the same forward and backward.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int total = 0;
        for (int i = 0; i < n; i++){
            int odd  = expandFromCenter(s, i, i);
            int even = expandFromCenter(s, i, i + 1);
            total += odd + even;
        }

        return total;
    }

    int expandFromCenter(string& s, int left, int right){
        int n = s.size();

        int total = 0;
        while (left >= 0 && right < n && s[left] == s[right]){
            total += 1;
            left  --;
            right ++;
        }
        return total;
    }
};

int main(){
    Solution sol;

    string s = "abc";
    cout << sol.countSubstrings(s) << endl;

    s = "aaa";
    cout << sol.countSubstrings(s) << endl;
}