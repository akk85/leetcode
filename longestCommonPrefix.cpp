#include "common.hpp"

/*
sorting the string vector makes use only have to compare the first and last string as there are the ones that differ the most

move a pointer as long char in both strings match
at the end the pointer will be at the first char that doesnt match and we can return string from first index to this index exclusive
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last  = strs[strs.size() - 1];

        size_t i = 0;

        while (i < first.size() && i < last.size() && first[i] == last[i]){
            i ++;
        }

        string result = first.substr(0, i);

        return result;
    }
};

int main(){
    Solution sol;

    vector<string> strs = {"bat","bag","bank","band"};

    cout << sol.longestCommonPrefix(strs) << endl;
}
