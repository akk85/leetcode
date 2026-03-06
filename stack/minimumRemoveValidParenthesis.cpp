#include "../common.hpp"

/*
Thought process:
    if opening incenrement count , if closing decrement
    if count is positive safe to append closing otherwise skip
    for opening we append regardless as we dont know whether we have clsoing in the future

    at the end if count is postive we have mismatching opening
    iterate in reverse and remove openings until count == 0;

*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;

        int count = 0;

        for (const char& ch : s){
            if (ch == ')' && count <= 0){
                continue;
            }

            else if (ch == ')' && count > 0){
                res += ch;
                count --;
            }
            else if (ch == '('){
                res += ch;
                count ++;
            }
            else {
                res += ch;
            }
        }

        string cleaned;

        for (int i = res.size() - 1; i >= 0; i--){
            char ch = res[i];

            if (ch == '(' && count > 0){
                count --;
                continue;
            }
            cleaned += ch;
        }

        reverse(cleaned.begin(), cleaned.end());

        return cleaned;



    }
};

int main(){
    Solution sol;

    string s = "lee(t(c)o)de)";

    cout << sol.minRemoveToMakeValid(s) << endl; // lee(t(c)o)de

    s = "a)b(c)d";

    cout << sol.minRemoveToMakeValid(s) << endl; // ab(c)d

    s = "))((";

    cout << sol.minRemoveToMakeValid(s) << endl; // []
}
