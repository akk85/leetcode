#include "../common.hpp"

/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.

Thought process:
    find each island and localize each island to start at orign 0,0 
    i.e find min row and min col and subract / normalize each cell in island 
    for island with same shape when normalized they will have same cordinates 
    we can use a set to track normalized islands 
    size of set will give us number of unique islands 
*/

class Solution {
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        set<vector<pair<int, int>>> islandsSet;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (grid[row][col] == 1){
                    vector<pair<int, int>> island = bfs(grid, row, col);

                    vector<pair<int, int>> signature = localizeIsland(island);
                    sort(signature.begin(), signature.end()); 
                    islandsSet.insert(signature);
                }
            }
        }

        return islandsSet.size();
    }

    vector<pair<int, int>> bfs(vector<vector<int>>& grid, int row, int col){
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0; // visited

        vector<pair<int, int>> ans;
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            ans.push_back({row, col});

            for (const auto& [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = 0; // visited
                }
            }
        }

        return ans;
    }

    vector<pair<int, int>> localizeIsland(vector<pair<int, int>>& island){
        int minRow = INT_MAX;
        int minCol = INT_MAX;

        for (const auto& [row, col] : island){
            minRow = min(minRow, row);
            minCol = min(minCol, col);
        }

        vector<pair<int, int>> normalized;
        for (const auto& [row, col] : island){
            int newRow = row - minRow;
            int newCol = col - minCol;
            normalized.push_back({newRow, newCol});
        }

        return normalized;
    }
};
