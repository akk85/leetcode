#include "../common.hpp"

/*
Given a string s, return the longest substring of s that is a palindrome.

A palindrome is a string that reads the same forward and backward.

If there are multiple palindromic substrings that have the same length, return any one of them.

intuition:
    for each char treat it as a middle of a palindrome and send out two pointers left and right to expand and find longest s
    palindrome size where this char is a pivot
    edge case handle cases when palidrome is of even number so start of left and right aadjacent to each other 
    for each char we can find longest palindrome length 

 left = mid - (length - 1) / 2;

        2 - 4 / 2 
abbc
 l
  r


*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        
        int maxLength = 0;
        
        for (int i = 0; i < n; i++){
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i + 1);
            int length = max(len1, len2);

            if (length > maxLength){
                start = i - (length - 1) / 2;
                maxLength = length;
            }

        }

        string result = s.substr(start, maxLength);
        return result;

    }

    int expandFromCenter(string s, int left, int right){
        int n = s.size();

        while(left >= 0 && right < n && s[left] == s[right]){
            left  --;
            right ++;
        }

        return right - left - 1;
    }

};

int main(){
    Solution sol;

    string s = "aba";
    cout << sol.longestPalindrome(s) << endl;

    s = "abbc";
    cout << sol.longestPalindrome(s) << endl;
}
