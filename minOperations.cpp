#include "common.hpp"

/*
The operations are described below:

"../" :Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).

"./" :Remain in the same folder.

"x/" :Move to the child folder named x (This folder is guaranteed to always exist).

*/
class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stack;

        string mainFolder = logs[0];
        for (const string& log : logs){
            // go to parent 
            if (log == "../"){
                if (!stack.empty()){
                    stack.pop();
                }
            } 
            // same folder 
            else if (log == "./"){
                continue;
            }
            else {
                stack.push(log);
            }
        }

        return stack.size();
    }
};

int main(){
    Solution sol;

    vector<string> logs = {"d1/","d2/","../","d21/","./"};

    cout << sol.minOperations(logs) << endl;

    logs = {"d1/","../","../","../"};

    cout << sol.minOperations(logs) << endl;

    logs = {"d1/","d2/","../","d3/","../","d4/","../","d5/"};

    cout << sol.minOperations(logs) << endl;

    logs = {"123/","a1b2/","../","xyz/","a1/","b2/","../","./","123/"};

    cout << sol.minOperations(logs) << endl;


}

/*
d21 
*/