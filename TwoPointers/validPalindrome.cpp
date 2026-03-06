#include "../common.hpp"
/*
Was it a car or a cat I saw?
l                          r

Time O(n) Space O(1)
*/


class Solution{
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r){
            while (l < r && !isalnum(s[l])){
                l++;
            }
            while (l < r && !isalnum(s[r])){
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main(){
    Solution sol;

    string s = "Was it a car or a cat I saw?"; //wasitacaroracatisaw
    cout << boolalpha << sol.isPalindrome(s) << endl;

    s = "tab a cat";   // tabacat
    cout << boolalpha << sol.isPalindrome(s) << endl;
}