#include "../common.hpp"

/*
reverse whole string then reverse each word
*/
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        reverse(s, 0, n - 1);
        reverseEachWord(s); 
    }
private:
    void mySwap(char& first, char& second){
        char temp = first;
        first     = second;
        second    = temp;
    }
    void reverse(vector<char>& s, int start, int end){
        int left = start, right = end;

        while (left < right){
            mySwap(s[left], s[right]);
            left  ++;
            right --;
        }
    }

    void reverseEachWord(vector<char>& s){
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

};

void printVector(const vector<char>& s) {
    for (char c : s) {
        cout << c;
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};

    printVector(s);

    sol.reverseWords(s);   

    printVector(s);
}

