#include "common.hpp"

/*
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

Intuition:
    Multi BFS from thief node to mark grid cells with distance from thief
    Greedy djikstras algo starting from (0,0) choosing maximum path.
    same time updating secondary grid with safeness for each cell where safeness for neighbor cell is equal to 
    min(safeness of cell we are coming from, value of neighbor cell in grid)
*/

#define THIEF 1
class Solution {
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void safenessofEachCell(vector<vector<int>>& grid){
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<bool>> visited(rows);
        for (int row = 0; row < rows; row ++){
            visited[row].resize(cols);  // default value for cell will be false 
        }

        queue<pair<int, int>> q;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (grid[row][col] == THIEF){
                    q.push({row, col});
                    grid[row][col] = 0;       // min distance of thief cells from thieves 
                    visited[row][col] = true; // thieves visited 
                }
            }
        }
        
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto [row, col] = q.front(); q.pop();

                for (const auto& [dr, dc] : directions){
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]){
                        q.push({nr, nc});
                        grid[nr][nc]    = dist;
                        visited[nr][nc] = true;
                    }
                }
            }
            dist ++;
        }
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        safenessofEachCell(grid);
        
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> safeness(rows, vector<int>(cols, -1));
        
        // run greedy djikstra maximizing route via maxheap
        priority_queue<tuple<int, int, int>> maxHeap;
        
        maxHeap.push({grid[0][0], 0, 0});
        safeness[0][0] = grid[0][0];

        while(!maxHeap.empty()){
            auto [distance, row, col] = maxHeap.top(); maxHeap.pop();

            if (row == rows - 1 && col == cols - 1){
                return safeness[row][col];           
            }
            for (const auto& [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && safeness[nr][nc] == -1){ // not visited
                    safeness[nr][nc] = min(safeness[row][col], grid[nr][nc]);
                    maxHeap.push({safeness[nr][nc], nr, nc});
                }
            }
        }

        return -1; // never get here
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1,0,0},
        {0,0,0},
        {0,0,1}
    };
    cout << sol.maximumSafenessFactor(grid1) << endl; // 0

    vector<vector<int>> grid2 = {
        {0,0,1},
        {0,0,0},
        {0,0,0}
    };
    cout << sol.maximumSafenessFactor(grid2) << endl; // 2

    vector<vector<int>> grid3 = {
        {0,0,0,1},
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0}
    };
    cout << sol.maximumSafenessFactor(grid3) << endl; // 2

    return 0;
}