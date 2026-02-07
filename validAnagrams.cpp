#include "common.hpp"

class Solution {
public:
    // using two maps O(n) time and O(n) space
    bool isAnagram1(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }

        // build two maps
        unordered_map<char, int> mapA; unordered_map<char, int> mapB; 

        for (const char& ch : s){
            mapA[ch] += 1;
        }
        for (const char& ch : t){
            mapB[ch] += 1;
        }

        return mapA == mapB;
    }

    // using only one map saves half the space. O(n) time and O(n) space 
    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> seen;
        for (const char& ch : s){
            seen[ch] += 1;
        }
        for (const char& ch : t){
            seen[ch] -= 1;
        }

        for (const auto pair : seen){
            if (pair.second != 0){
                return false;
            }
        }
        return true;
    }

    bool isAnagram4(string s, string t){
        if (s.size() != t.size()){
            return false;
        }
        
        vector<int> vec(26, 0);

        for (const char& ch : s){
            vec[ch - 'a'] ++;
        }
        for (const char& ch : t){
            vec[ch - 'a'] --;
        }

        for (const int& pos : vec){
            if (pos != 0){
                return false;
            }
        }
        
        return true;
    }
    // sort the strings and check characters  O(nlogn) time and O(1) extra space. 
    bool isAnagram3(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    // 
};

int main(){
    Solution sol;
    string s = "racecar"; string t = "carrace";
    cout << boolalpha << sol.isAnagram1(s, t) << endl;
    cout << boolalpha << sol.isAnagram2(s, t) << endl;
    cout << boolalpha << sol.isAnagram3(s, t) << endl;
    cout << boolalpha << sol.isAnagram4(s, t) << endl;

    s = "jar"; t = "jam";
    cout << boolalpha << sol.isAnagram1(s, t) << endl;
    cout << boolalpha << sol.isAnagram2(s, t) << endl;
    cout << boolalpha << sol.isAnagram3(s, t) << endl;
    cout << boolalpha << sol.isAnagram4(s, t) << endl;
}