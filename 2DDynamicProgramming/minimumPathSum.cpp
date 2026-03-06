#include "../common.hpp"

/*
You are given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Thought process:
    bottom up approach starting from destination cell backtrack up
    for each cell the path cost for that cell will be the cell + min (right cell and bottom cell) as those are the only two path choices we can take from this cell
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> paths(rows + 1);
        for (int row = 0; row < paths.size(); row ++){
            paths[row].resize(cols + 1);
        }

        // bottom row and right cell filled with infinity
        for (int col = 0; col < paths[0].size(); col ++){
            paths[rows][col] = INT_MAX;
        } 

        for (int row = 0; row < paths.size(); row ++){
            paths[row][cols] = INT_MAX;
        }

        paths[rows][cols - 1] = 0;

        // start dp
        for (int row = rows - 1; row >= 0; row --){
            for (int col = cols - 1; col >= 0; col --){
                int right  = paths[row][col + 1];
                int bottom = paths[row + 1][col];
                paths[row][col] = grid[row][col] + min(right, bottom);
            }
        }

        return paths[0][0];
    }   
    // space optimized using constant space by mutating the input grid 
    int minPathSumOptimized(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        // last row
        for (int col = cols - 2; col >= 0 ; col --){
            grid[rows - 1][col] = grid[rows - 1][col] + grid[rows - 1][col + 1];
        }

        // last column
        for (int row = rows - 2; row >= 0; row --){
            grid[row][cols - 1] = grid[row][cols - 1] + grid[row + 1][cols - 1];
        }

        for (int row = rows - 2; row >= 0; row --){
            for (int col = cols - 2; col >= 0; col --){
                int right  = grid[row][col + 1];
                int bottom = grid[row + 1][col];
                grid[row][col] = grid[row][col] + min(right, bottom);
            }
        }

        return grid[0][0];
    }
};


int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << sol.minPathSum(grid) << endl; // 7
    cout << sol.minPathSumOptimized(grid) << endl; // 7
}