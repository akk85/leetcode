
#include "../common.hpp"

/*

You are given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 

of the characters without disturbing the relative positions of the remaining characters.

(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

inutiotion
    two pointers at s and t
    as long as both pointes match charactes move them both otherwise move t pointer
    exit loop when s pointer reaches end of s string

    return true if s pointer reached end of string meaning found matching char for each pointer 
*/





class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()){
            if (s[i] == t[j]){
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == s.size();
    }
};