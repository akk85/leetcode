#include "common.hpp"

/*
You are given an array of characters which represents a string s. Write a function which reverses a string.

You must do this by modifying the input array in-place with O(1) extra memory.

Intuition:
    use two pointers left and right and swap elements until they meet 

["r","a","c","e","c","a","r"]

*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t l = 0;
        size_t r = s.size() - 1;

        while(l < r){
            swap(s[l], s[r]);
            l ++;
            r --;
        }
    }
};

void print(vector<char>& s){
    for (const char& ch : s){
        cout << ch << " ";
    }
    cout << endl;
}
int main(){
    Solution sol;

    vector<char> s = {'n', 'e', 'e', 't'};

    sol.reverseString(s);
    print(s);
}