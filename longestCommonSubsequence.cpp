#include "common.hpp"

/*
Given two strings text1 and text2, return the length of the longest common subsequence between the two strings if one exists, otherwise return 0.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the relative order of the remaining characters.

For example, "cat" is a subsequence of "crabt".
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size() + 1;
        int cols = text2.size() + 1;
        vector<vector<int>> dp(rows);
        for (int vec = 0; vec < rows; vec++){
            dp[vec].resize(cols);
        }

        for (int row = rows - 2; row >= 0 ; row--){
            for (int col = cols - 2; col >= 0; col --){
                if (text1[row] == text2[col]){
                    dp[row][col] = 1 + dp[row + 1][col + 1];
                }
                else {
                    int right  = dp[row][col + 1];
                    int bottom = dp[row + 1][col];
                    dp[row][col] = max(right, bottom);
                }
            }
        }

        return dp[0][0];
    }
};

int main(){
    Solution sol;

    string text1 = "cat";
    string text2 = "crabt";

    cout << sol.longestCommonSubsequence(text1, text2) << endl; // 3
}
