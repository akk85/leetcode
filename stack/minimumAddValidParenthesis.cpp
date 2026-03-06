#include "../common.hpp"

/*
we can count opening and closing parenthesis

Intution:
    Each opening parenthesis needs a closing parenthesis regardless of where it is
    Each closing parenthesis can be completed by an already seen opening paran or will need us to add a brand new opening one
    so if we see an opening parenthessi we add it to our tally
    if we see a closing parenthesis,  
                        * if our opening tally is more than zero we complement it by an alredy seen parenthsis by decremeneting our opening tally
                        * if our opening tally is zero we will need to add a new opening so we increment closing tally 

    at the end we can just return total number of mismatched opening + closing 
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0 , closing = 0;

        for (const char& par : s){
            if (par == '('){
                opening ++;
            }
            else if (par == ')' && opening > 0){
                opening --;
            }
            else {
                closing ++;
            }
        }

        return opening + closing;
    }
};

int main(){
    Solution sol;

    string s = "())";

    cout << sol.minAddToMakeValid(s) << endl; // 1

    s = "(((";

    cout << sol.minAddToMakeValid(s) << endl; // 3

    s = "()))";

    cout << sol.minAddToMakeValid(s) << endl; // 2
}
