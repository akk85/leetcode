#include "../common.hpp"

/*
Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.

An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. 
You may assume water is surrounding the grid (i.e., all the edges are water).

Thought process:
    1. traverse each cell in the grid.
    2. if this cell is a land, means its a beginning of an island, therefore increment island counter and do a bfs search from this cell
    3. in the bfs visit all lands in this corresponding island and mark them as visited so that not to vist them again
    4. I can just mark visited lands as '0' water this will make me not visit them in the grid traversal

*/

class Solution {
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1},{-1, 0}, {1, 0}};
    void visitIsland(vector<vector<char>>& grid, int row, int col){
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});   grid[row][col] = '0'; // visited

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (const auto [dr, dc] : directions){
                int nr = row + dr;
                int nc = row + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';  // visited 
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        int islands = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (grid[row][col] == '1'){
                    visitIsland(grid, row, col);
                    islands += 1;
                }
            }
        }

        return islands;
    }
};