#include "../common.hpp"

/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). 

You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

class Solution {
private:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<int>> effortGrid(rows);
        for (int row = 0; row < rows; row ++){
            effortGrid[row].resize(cols);
        }

        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                effortGrid[row][col] = INT_MAX;
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push({0,0,0});
        effortGrid[0][0] = 0;

        while(!minHeap.empty()){
            auto [effort, row, col] = minHeap.top(); minHeap.pop();

            if (row == rows - 1 && col == cols - 1){
                return effort;
            }

            if (effort > effortGrid[row][col]){
                continue;
            }

            for (const auto& [dr, dc] : directions){
                int nRow = row + dr;
                int nCol = col + dc;

                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols){
                    int weight    = abs(heights[row][col] - heights[nRow][nCol]);
                    int newEffort = max(effort, weight);

                    if (newEffort < effortGrid[nRow][nCol]){
                        effortGrid[nRow][nCol] = newEffort;
                        minHeap.push({newEffort, nRow, nCol});
                    }
                }
            }
        }

        return 0; // never reached 

    }
};

int main() {
    Solution sol;

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << sol.minimumEffortPath(heights) << endl;
    
    return 0;
}