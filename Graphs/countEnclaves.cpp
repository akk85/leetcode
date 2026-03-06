#include "../common.hpp"

/*
mark all border connected islands as zeros 
run through matrix again and find lands still marked as 1 and return their count 
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        findBorderLands(grid);
        int enclaves = countRemainingLands(grid);

        return enclaves;
    }
private:
    vector<pair<int, int>> directions {{0, -1},  {0,  1}, {-1, 0}, {1,  0} };
    void findBorderLands(vector<vector<int>>& grid){
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) && grid[row][col] == 1){
                    grid[row][col] = 0;
                    q.push({row, col});
                }
            }
        } 

        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (auto& [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
    }

    int countRemainingLands(vector<vector<int>>& grid){
        int rows = grid.size(), cols = grid[0].size();

        int count = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (grid[row][col] == 1) count ++;
            }
        } 

        return count; 
    }
};