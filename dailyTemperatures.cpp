#include "common.hpp"

/*
You are given an array of integers temperatures where temperatures[i] 
represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer
temperature appears on a future day. 
 
If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.

thought process:
    using a stack we can keep temperatures in a monotic decreasing manner 
    i.e if curr temperature is less than previous day we add it into stack
    otherwise if greater then we know we found a greater temperature and we can pop and update return list with index 

    in the stack we also keep track of index for ease of updating number of days it took us to find a warmer day 

Input: temperatures = 

output = 1  4. 1. 2.  1. 0 0 
        [30,38,30,36,35,40,28]

stack =  28

Output: [1,4,1,2,1,0,0]

pseudo code:
    create array of size n prefilled with zeroes
    for each value in temperature
        while this value is greater than stack top
            pop from stack
            update result with difference in index
        append into stack

*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> stack;   // temp index
        for (int i = 0; i < n; i++){
            int temp = temperatures[i];
            while (!stack.empty() && temp > stack.top().first){
                auto [prevTemp, previndex] = stack.top(); stack.pop();
                int diff = i - previndex;
                res[previndex] = diff;
            }
            stack.push({temp, i});
        }

        return res;
    }

    void printResult(const vector<int>& result){
        for (const int& val : result){
            cout << val << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution sol;

    vector<int> temperature = {30,38,30,36,35,40,28};

    vector<int> result = sol.dailyTemperatures(temperature);

    sol.printResult(result);
}