#include "../common.hpp"

/*
The first ten characters consist of the phone number of passengers.
The next character denotes the gender of the person.
The following two characters are used to indicate the age of the person.
The last two characters determine the seat allotted to that person.
*/
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count {};
        for (const string& st : details){
            int age = stoi(st.substr(11, 2));

            if (age > 60){
                count ++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;

    vector<string> details = {"7868190130M7522","5303914400F9211","9273338290F4010"};

    cout << sol.countSeniors(details) << endl;


    details = {"1313579440F2036","2921522980M5644"};

    cout << sol.countSeniors(details) << endl;

}