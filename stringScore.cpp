#include "common.hpp"

class Solution {
public:
    int scoreOfString(string s) {
        int score {};
        for (size_t i = 1; i < s.size(); i++){
            score += abs(s[i] - s[i-1]);
        }

        return score;
    }
};


int main(){
    Solution s;
    cout << s.scoreOfString("code") << endl;  // 24
    cout << s.scoreOfString("neetcode") << endl;  // 65
}