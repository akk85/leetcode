#include "common.hpp"


/*
You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.

thought process:
    use a stack to append all int values
    upon seeing an operators, pop top two elemnts in stack. apply operand on them and push the result value to the stack
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = st.top(); st.pop();
                int left  = st.top(); st.pop();
                int result;

                if (token == "+") result = left + right;
                else if (token == "-") result = left - right;
                else if (token == "*") result = left * right;
                else result = left / right;  

                st.push(result);
            } 
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};


int main(){
    Solution sol;

    vector<string> tokens = {"1","2","+","3","*","4","-"}; // 5
    cout << sol.evalRPN(tokens) << endl; 

    
    tokens = {"2","1","+","3","*"}; // 9
    cout << sol.evalRPN(tokens) << endl; 

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}; // 22
    cout << sol.evalRPN(tokens) << endl; 
}