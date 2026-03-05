#include "common.hpp"

/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

It starts raining, and water gradually rises over time. 

At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares 
individually are at most t. You can swim infinite distances in zero time. 

Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

*/

class Solution {
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<bool>> visited(rows); // 2d grid default initialized to false 
        for (int row = 0; row < rows; row ++){
            visited[row].resize(cols);
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push({0,0,0});
        visited[0][0] = true;

        while(!minHeap.empty()){
            auto [height, row, col] = minHeap.top(); minHeap.pop();

            if (row == rows - 1 && col == cols - 1){
                return height;
            }

            for (const auto& [dr, dc] : directions){
                int nRow = row + dr;
                int nCol = col + dc;

                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && !visited[nRow][nCol]){
                    int newHeight = max(height, grid[nRow][nCol]);
                    minHeap.push({newHeight, nRow, nCol});
                    visited[nRow][nCol] = true;   // visited
                }
            }
        }

        return 0; // never get here
    }
};

int main(){
    Solution sol;

    vector<vector<int>> heights = {
        {0, 2},
        {1, 3}
    };

    cout << sol.swimInWater(heights) << endl; // 3 

    heights = {
        {0,  1,  2,  3,  4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9,  8,  7,  6}
    };

    cout << sol.swimInWater(heights) << endl; // 16
}