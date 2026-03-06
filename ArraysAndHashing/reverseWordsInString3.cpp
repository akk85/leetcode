#include "../common.hpp"
/*
Given a string s, reverse the order of characters in each word within a sentence 

while still preserving whitespace and initial word order.


Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int left  = 0, right = 0;

        while (left < n){
            while (right < n && s[right] != ' ') right++;
            reverse(s, left, right - 1);

            left  = right + 1;
            right += 1;
        }

        return s;
    }
private:
    void mySwap(char& first, char& second){
        char temp = first;
        first     = second;
        second    = temp;
    }

    void reverse(string& s, int start, int end){
        int left = start, right = end;

        while (left < right){
            mySwap(s[left], s[right]);
            left  ++;
            right --;
        }
    }
};

int main(){
    Solution sol;

    string s = "Let's take LeetCode contest";

    cout << sol.reverseWords(s) << endl;   //  "s'teL ekat edoCteeL tsetnoc"

    s = "Mr Ding";

    cout << sol.reverseWords(s) << endl;  // "rM gniD"
}