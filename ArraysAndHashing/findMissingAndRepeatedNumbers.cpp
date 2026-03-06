#include "../common.hpp"


/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
Each integer appears exactly once except a which appears twice and b which is missing. 
The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/

class Solution {
public:
    // time is O(n^2) and space is O(n^2)
    vector<int> findMissingAndRepeatedValues1(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        int repeated  {};
        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++){
                if (!seen.count(grid[r][c])){
                    seen.insert(grid[r][c]);
                } else {
                    repeated = grid[r][c];
                }
            }
        }

        int missing = {};
        for (int i = 1; i <= n*n; i++){
            if (!seen.count(i)){
                missing = i;
            }
        }

        return {repeated, missing};
    }

    // time is O(n^2) and 0(n^2) space
    vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        int repeated  {};
        int setSum  = {};
        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++){
                if (!seen.count(grid[r][c])){
                    seen.insert(grid[r][c]);
                    setSum += grid[r][c];
                } else {
                    repeated = grid[r][c];
                }
            }
        }

        int k = n * n;
        int expected = k * (k + 1) / 2;
        int missing = expected - setSum;
        return {repeated, missing};
    }
    void print(vector<int> vec){
        for (const int& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    
};


int main(){
    Solution sol;

    vector<vector<int>> grid = {
                                {1,3},
                                {2,2}
                                };
    vector<int> res = sol.findMissingAndRepeatedValues1(grid);
    sol.print(res);               // {2,4}

    res = sol.findMissingAndRepeatedValues2(grid);
    sol.print(res);  

    grid = {
        {9,1,7},
        {8,9,2},
        {3,4,6}
    };
    res = sol.findMissingAndRepeatedValues1(grid);
    sol.print(res);        // {9, 5}

    res = sol.findMissingAndRepeatedValues2(grid);
    sol.print(res);  

}