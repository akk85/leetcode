#include "../common.hpp"

/*
You are given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-(2^31), (2^31)-1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


Intuition:
    1. track curr number and prev operation
    2. when we iterate over string and find an operation, we apply the previous operation to the previous number before operation
    3. we update prev operation with this operation and so on
    4. for + we push to stack, -, we push - number, for * we pop from stack and multiply with curr number and for / we pop and diviide with current number


pseudo code
    string strip spaces

    currValue = 0
    prevOp = +
    for (int i = 0 to n - 1)
        if nums[i] is digit
            currValue = nums[i]

        if not a digit or its the last digit
            if prevop == +
                add num to stack
            if prevop = -
                add -num to stack
            if prevop = *
                pop from stack
                result = stack.pop * currnum
                stack.push(result)
            if prevop = /
                pop from stack
                result = stack.top / currnum
                stack.poush(result)
            currnum = 0;
            preop = nums[i]

    add all digits in stack
    return sum
*/

class Solution {
public:
    int calculate(string s) {
        string cleaned;
        for (const char ch : s){
            if (ch != ' ') cleaned += ch;
        }

        s = cleaned;

        int n = s.size();
        stack<int> stk;

        
        int currNum = 0;
        char prevOp = '+';
        for (int i = 0; i < n; i++){
            char currentChar = s[i];

            
            if (isdigit(currentChar)) currNum = currNum * 10 + (currentChar -'0');

            if (!isdigit(currentChar) || i == n - 1){
                if (prevOp == '+') stk.push(currNum);

                if (prevOp == '-') stk.push(-currNum);

                if (prevOp == '*') {
                    int prevNum = stk.top(); stk.pop();
                    int result  = prevNum * currNum;
                    stk.push(result); 
                }

                if (prevOp == '/') {
                    int prevNum = stk.top(); stk.pop();
                    int result  = prevNum / currNum;
                    stk.push(result); 
                }

                currNum = 0;
                prevOp = currentChar;
            }
        }

        int sum = 0;
        while(!stk.empty()){
            int curr = stk.top(); stk.pop();
            sum += curr;
        }

        return sum;
    }
};

int main(){
    Solution sol;

    string s = "12+3*4-5 ";

    cout << sol.calculate(s) << endl; // 19
}