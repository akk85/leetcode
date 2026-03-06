#include "../common.hpp"

/*
A distinct string is a string that is present only once in an array.

You are given an array of strings arr, and an integer k, 

return the k-th distinct string present in arr. 

If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.
*/
/*
build map of each sring to its freq

iterate vector string rfrom front and return kth string element that has freq of 1

*/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;

        for (const string& str : arr){
            freq[str] += 1;
        }

        int n = 0;
        for (const string& str : arr){
            if (freq[str] == 1){
                n++;
            }
            if (n == k){
                return str;
            }

        }
        return "";
    }
};

int main(){
    Solution sol;

    vector<string> arr = {"d","b","c","b","c","a"};  // a

    cout << sol.kthDistinct(arr, 2) << endl;

    arr = {"aaa","aa","a"};  // aaa

    cout << sol.kthDistinct(arr, 1) << endl;

    arr = {"a","b","a"};  // none

    cout << sol.kthDistinct(arr, 3) << endl;
}