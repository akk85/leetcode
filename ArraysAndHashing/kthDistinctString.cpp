#include "../common.hpp"

/*
A distinct string is a string that is present only once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".

Note that the strings are considered in the order in which they appear in the array.

d = 1
b = 2
c = 2
a = 1

d","b","c","b","c","a

res = [d , a].  // a 


aaa 1
aa  1
1   1

"aaa","aa","a"

res = [aaa, aa, a]

a 2
b 1

"a","b","a"

res = [b].  return ""
*/
class Solution {
public:
    // Time O(n) and space is O(n)
    string kthDistinct1(vector<string>& arr, int k) {
        unordered_map< string, int > counter;
        for (const string& str : arr){
            counter[str] ++;
        }

        vector<string> res;
        for (const string& str : arr){
            if (counter[str] == 1){
                res.push_back(str);
            }
        }

        if (static_cast<int>(res.size()) < k){
            return "";
        }

        return res[k-1];
    }
    // Time O(n) and space is O(n) just better mspace saving by getting rid of the vector 
    string kthDistinct2(vector<string>& arr, int k) {
        unordered_map< string, int > counter;
        for (const string& str : arr){
            counter[str] ++;
        }

        for (const string& str : arr){
            if (counter[str] == 1){
                k --;
                if (k == 0){
                    return str;
                }
            }
        }

        return "";

    }
};


int main(){
    Solution sol;

    vector<string> arr = {"d","b","c","b","c","a"}; int k = 2;       //a
    string answer = sol.kthDistinct1(arr, k);
    cout << answer << endl;

    answer = sol.kthDistinct2(arr, k);
    cout << answer << endl;

    arr = {"aaa","aa","a"}; k = 1;         // aaa
    answer = sol.kthDistinct1(arr, k);
    cout << answer << endl;

    answer = sol.kthDistinct2(arr, k);
    cout << answer << endl;

    arr = {"a","b","a"}; k = 3;             //  ""
    answer = sol.kthDistinct1(arr, k);
    cout << answer << endl;

    answer = sol.kthDistinct2(arr, k);
    cout << answer << endl;

}