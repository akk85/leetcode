/*
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

*/

#include "../common.hpp"

class Solution {
public:
    // Using a hashmap Time O(n * klog k) and Space is O(n)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
        // build hashmap of anagrams 
        for (const string& word : strs){
            string key = word;
            sort(key.begin(), key.end());
            map[key].push_back(word);
        }

        // retrive the vector of anagrams in map
        vector<vector<string>> res;
        for (const auto& pair : map){
            res.push_back(pair.second);
        }

        return res;
    }

    void print(const vector<vector<string>>& res) {
        cout << "[";
        for (size_t i = 0; i < res.size(); i++) {
            cout << "[";
            for (size_t j = 0; j < res[i].size(); j++) {
                cout << "\"" << res[i][j] << "\"";
                if (j + 1 < res[i].size()) cout << ", ";
            }
            cout << "]";
            if (i + 1 < res.size()) cout << ", ";
        }
        cout << "]" << endl;
    }


};

int main(){
    Solution sol;

    vector<string> strs = {"act","pots","tops","cat","stop","hat"};


    vector<vector<string>> output = sol.groupAnagrams(strs);

    sol.print(output);


}