#include "common.hpp"

/*
You are given a string s, return true if the s can be a palindrome after deleting at most one character from it.

A palindrome is a string that reads the same forward and backward.

Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

intuition:
    if left and right char dont match check if string from left + 1 to right is a plaindrome or string from right to left + 1 is a palindrome
    we just skip one of the char
abdceecba
  l   r

*/


class Solution {
public:
    bool validPalindrome(string s) {
        size_t l = 0;
        size_t r = s.size() - 1;

        while (l < r){
            if (s[l] == s[r]){
                l ++;
                r --;
            }
            else {
                string skipLeft  = s.substr(0, l) + s.substr(l + 1);
                string skipRight = s.substr(0, r) + s.substr(r + 1);
                return isPalindrome(skipLeft) || isPalindrome(skipRight);
            }
        }

        return true;

    }
    bool isPalindrome(string s){
        size_t l = 0;
        size_t r = s.size() - 1;

        while (l < r){
            if (s[l] != s[r]){
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
};

int main(){
    Solution sol;

    string s = "aca";

    cout << boolalpha << sol.validPalindrome(s) << endl;
}