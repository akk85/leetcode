#include "common.hpp"


class Solution {
public:
    bool isIsomorphic(string s, string t);
};


int main(){
    Solution sol;
    string s = "egg"; string t = "add";
    cout << boolalpha << sol.isIsomorphic(s,t) << endl;

    s = "foo"; t = "bar";
    cout << boolalpha << sol.isIsomorphic(s,t) << endl;

    s = "paper"; t = "title";
    cout << boolalpha << sol.isIsomorphic(s,t) << endl;
}