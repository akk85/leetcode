#include "../common.hpp"

/*
You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.

Can you write a solution that runs in O(log(m * n)) time?

Intution
    1. Find the row where this value might be as using binary search
    2. Find if this value is in this row by doing binary search again on row
    3. return true if found else false;

pseudo code
    int findRow(grid, target)
        int l = 0
        int r = rows - 1
        while l < r
            int m = (l + r) / 2
            if target > row last element
            l = m + 1
            elif if target < row first element
            r = m - 1
            else    
                return m

        return -1
    
    bool searchMatrix(grid, target)
        int row = findRow(grid, target);
        if (row == -1) return false;

        bool result = binarySearchRow(grid, row, target)
        return result

    bool binarySearchRow(grid, row, target)
        int l = 0
        int r = cols - 1
        while l < r
            m = (l + r) / 2
            if target > grid[row][m]
                l = m + 1
            elif target < grid[row][m]
                r = m - 1
            else 
                return true

        return false;
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix, target);
        if (row == -1) return false;

        return binarySearchRow(matrix, row, target);
    }

private:
    int findRow(vector<vector<int>>& matrix, int target){
        int rows = matrix.size(); int cols = matrix[0].size();
        int l = 0;
        int r = rows - 1;

        while (l <= r){
            int m = (l + r) / 2;
            int firstElement = matrix[m][0];
            int lastElement  = matrix[m][cols - 1];
            if (target > lastElement){
                l = m + 1;
            }
            else if (target < firstElement){
                r = m - 1;
            }
            else {
                return m;
            }
        }
        return -1;
    }

    bool binarySearchRow(vector<vector<int>>& matrix, int row, int target){
        int cols = matrix[0].size();
        int l = 0;
        int r = cols - 1;

        while (l <= r){
            int m = (l + r) / 2;

            if (target > matrix[row][m]){
                l = m + 1;
            }
            else if (target < matrix[row][m]){
                r = m - 1;
            } 
            else {
                return true;
            }
        }
        return false;
    }
};


int main(){
    Solution sol;

    vector<vector<int>> matrix = {
        {1,  2,   4,  8},
        {10, 11, 12, 13},
        {14, 20, 30, 40}
    };

    cout << boolalpha << sol.searchMatrix(matrix, 10) << endl;
}