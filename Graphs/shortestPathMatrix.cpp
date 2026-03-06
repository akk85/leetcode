#include "../common.hpp"

/*
You are given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 

If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell 
(i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they 
share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/

class Solution {
private:
    vector<pair<int, int>> directions = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0},
        {-1,-1}, {-1,1}, {1, -1}, {1, 1}
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        set<pair<int, int>> visited;
        queue<tuple<int, int, int>> q; // row, col, dist
        q.push({0,0,1});
        visited.insert({0,0});

        while(!q.empty()){
            auto [row, col, dist] = q.front(); q.pop();

            if ((row == rows - 1) && (col == cols - 1)){
                return dist;
            }

            for (const auto& [dr, dc] : directions){
                int nRow = row + dr;
                int nCol = col + dc;

                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && !visited.contains({nRow, nCol}) && grid[nRow][nCol] == 0){
                    q.push({nRow, nCol, dist + 1});
                    visited.insert({nRow, nCol});
                }
            }
        }

        return -1; // bottom right not reached
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {0,1,0,1},
        {1,0,0,1},
        {0,1,1,1},
        {1,0,0,0}
    };

    cout << sol.shortestPathBinaryMatrix(grid) << endl; // 6
}