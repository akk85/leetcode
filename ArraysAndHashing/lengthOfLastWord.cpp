#include "../common.hpp"

class Solution {
public:
    // start from the end: time O(n) and O(1) space
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0;
        int i = n - 1;
        while (i >= 0 && s[i] == ' '){
            i--;
        }

        while (i >= 0 && s[i] != ' '){
            i--;
            length ++;
        }
        return length;
    }
};

int main(){
    Solution sol;
    string s = "Hello World";
    string t = "   fly me   to   the moon  ";
    string v = "luffy is still joyboy";
    string w = "     ";

    cout << sol.lengthOfLastWord(s) << endl;
    cout << sol.lengthOfLastWord(t) << endl;
    cout << sol.lengthOfLastWord(v) << endl;
    cout << sol.lengthOfLastWord(w) << endl;
}