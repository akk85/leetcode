#include "../common.hpp"

/*
use two pointers 
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0;
        int r = 0;

        string newS;

        while (l < word1.size() && r < word2.size()){
            newS += word1[l];
            newS += word2[r];
            l ++;
            r ++;
        }

        if (l < word1.size()){
            newS += word1.substr(l);
        }
        if (r < word2.size()){
            newS += word2.substr(r);
        }

        return newS;
    }
};

int main(){
    Solution sol;

    string word1 = "ab"; string word2 = "abbxxc";

    cout << sol.mergeAlternately(word1, word2) << endl;
}