#include "common.hpp"

/*
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

intuition 
    use a map to map closing parenthesis to opening 
([{}])

    iterate over the parenthisi 
        if open push to stack
        if closing check stack is not empty and that top paren matches that of the closing parenthis 
            * pop if true* 
            * return false 

    return true end if stack is empty emaning all opeing were closed 

pseudo code
    build map
    ) (
    ] [
    } {

    opening parenthisis = ( , [ , {
    for each parenthesis in array
        if parenthis in opening
            stack.push(paren)
        else
            if stack not empty and stack[top] matches with map[curr pare]
                stack.pop()
            else 
                return false 

    return stack is empty
*/


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closingToOpening;

        closingToOpening[')'] = '(';
        closingToOpening[']'] = '[';
        closingToOpening['}'] = '{';

        stack<char> stk;

        for (const char& par : s){
            if (!closingToOpening.contains(par)){
                stk.push(par);
            } 
            else {
                if (!stk.empty() && stk.top() == closingToOpening[par]){
                    stk.pop();
                }
                else {
                    return false;
                }
            }
        }

        return stk.empty();
        
    }
};

int main(){
    Solution sol;

    string s = "[]"; // true
    cout << boolalpha << sol.isValid(s) << endl;

    s = "([{}])";  // true 
    cout << boolalpha << sol.isValid(s) << endl;

    s = "[(])"; // false
    cout << boolalpha << sol.isValid(s) << endl;

}