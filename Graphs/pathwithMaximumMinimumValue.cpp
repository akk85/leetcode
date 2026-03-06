#include "../common.hpp"

/*
Given an m x n integer matrix grid, return the maximum score of a path starting at (0, 0) and ending at (m - 1, n - 1) moving in the 4 cardinal directions.

The score of a path is the minimum value in that path.

For example, the score of the path 8 → 4 → 5 → 9 is 4.
*/

class Solution{
private:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int maximumMinimuValue(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> path(rows);
        for (int row = 0; row < rows; row ++){
            path[row].resize(cols);
        }

        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                path[row][col] = INT_MAX;
            }
        }
        priority_queue<tuple<int, int, int>> maxHeap;
        
        maxHeap.push({grid[0][0], 0, 0});
        path[0][0] = grid[0][0]; 

        while(!maxHeap.empty()){
            auto [weight, row, col] = maxHeap.top(); maxHeap.pop();

            if (row == rows - 1 && col == cols - 1){
                return path[row][col];
            }

            for (const auto& [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && path[nr][nc] == INT_MAX){
                    path[nr][nc] = min(path[row][col], grid[nr][nc]);
                    maxHeap.push({grid[nr][nc], nr, nc});
                }
            }
        }

        return -1; // will never get here 
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {5,4,5},
        {1,2,6},
        {7,4,6}
    };

    cout << sol.maximumMinimuValue(grid) << endl; // 4

    grid = {
        {2,2,1,2,2,2},
        {1,2,2,2,1,2}
    };

    cout << sol.maximumMinimuValue(grid) << endl; // 2

    grid = {
        {3,4,6,3,4},
        {0,2,1,1,7},
        {8,8,3,2,7},
        {3,2,4,9,8},
        {4,1,2,0,0},
        {4,6,5,4,3}
    };

    cout << sol.maximumMinimuValue(grid) << endl; // 3

    grid = {
        {5,4,5},
        {1,2,6},
        {7,4,6}
    };

    cout << sol.maximumMinimuValue(grid) << endl; // 4

}