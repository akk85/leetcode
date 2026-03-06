#include "../common.hpp"

/*
There is an m x n grid where you are allowed to move either down or to the right at any point in time.

Given the two integers m and n, return the number of possible unique paths that can be taken from the top-left corner of the grid (grid[0][0]) to the bottom-right corner (grid[m - 1][n - 1]).

You may assume the output will fit in a 32-bit integer.

Thought process:
    for every cell we are only allowed to go right or down

    1. for all cells in the bottow row we can only move right since down is out of bounds 
       so that means only 1 unique path for all bottom cells 
    2. for all cells in the right most column we can only move down since right is out of bounds 
        so only 1 unique path for each cell in the right cell
    3. starting from the bottom right cell we can backtrack updating how many paths we can get from each cell 
        which would be the addition of its immediate right and down cell and do that until we reach the first cell 

    pseudo code
        create a m * n vector matix initialized to 0
        last row and last column iniyizlized to 1
        for rows m - 1 to 0 and cols n - 1 to 0
            for each cell
                rightcell = [row][col + 1]
                down cell = [row + 1][col]
                value for this cell = rightcell + downcell

        return [0][0]
*/

class Solution {
public:
    int uniquePaths(int m, int n) {

        // vector of size m * n all zeros 
        vector<vector<int>> paths(m);
        for (int vec = 0; vec < m; vec++){
            paths[vec].resize(n);
        }

        // bottom row
        int lastRow = m - 1;
        for (int col = 0; col < n; col++){
            paths[lastRow][col] = 1;
        }

        // right colum
        int lastCol = n - 1;
        for (int row = 0; row < m; row++){
            paths[row][lastCol] = 1;
        }

        // fill rest cells 
        for (int row = m - 2; row >= 0; row --){
            for (int col = n - 2; col >= 0; col --){
                int rightCell  = paths[row][col + 1];
                int bottomCell = paths[row + 1][col];
                paths[row][col] = rightCell + bottomCell; 
            }
        }

        return paths[0][0];
    }
};

int main(){
    Solution sol;

    cout << sol.uniquePaths(3, 7) << endl;  // 28

    cout << sol.uniquePaths(3, 6) << endl;  // 21

    cout << sol.uniquePaths(3, 3) << endl;  // 6
}
