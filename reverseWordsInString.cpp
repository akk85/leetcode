#include "common.hpp"

/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 

The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 

The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

class Solution {
private:
    void trimSpaces(string& s){
        int n = s.size();
        int left  = 0;
        int right = 0;

        // skip leading spaces
        while (right < n && s[right] == ' ') right ++;

        while (right < n){
            // if not space write right into left 
            // if space wrte one space into left and skip all consecutive spaces in right 
            if (s[right] != ' '){
                s[left] = s[right];
                left  ++;
                right ++;
            } 
            else {
                s[left] = ' ';
                left ++;
                while (right < n && s[right] == ' ') right ++;
            }
        }

        // remove trailing spaces if any 
        if (left > 0 && s[left - 1] == ' ') left --;
        s.resize(left);
    }
    void reverse(string& s, int start, int end){
        int left  = start;
        int right = end;

        while (left < right){
            swap(s[left], s[right]);
            left  ++;
            right --;
        }
    }

    void reverseEachWord(string& s){
        int n = s.size();
        int left  = 0;
        int right = 0;
        while (left < n){
            while (right < n && s[right] != ' ') right ++;

            reverse(s, left, right - 1);

            left   = right + 1;
            right += 1;
        }
    }
public:
    string reverseWords(string s) {
        trimSpaces(s);
        
        int n = s.size();
        reverse(s, 0, n - 1);

        reverseEachWord(s);
        return s;
    }


};


int main(){
    Solution sol;

    string s = "the sky is blue";

    cout << sol.reverseWords(s) << endl;   //  "blue is sky the"

    s = "  hello world  ";

    cout << sol.reverseWords(s) << endl;  // "world hello"
}