#include "../common.hpp"

/*
You are given an m x n matrix grid and a positive integer k. 
An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).

The total value of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value divisible by k.

Thought Process:
    Question is trivial and builds upon number of islands area;
    find each islands area and if area is divisiable by k with no remainder increment our count. 
*/

class Solution {
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    long long bfs(vector<vector<int>>& grid, int row, int col){
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

        long long area = 0;
        area += grid[row][col];

        grid[row][col] = 0; // mark as visited


        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (const auto& [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != 0){
                    area += grid[nr][nc];
                    q.push({nr, nc});
                    grid[nr][nc] = 0; // visited
                }
            }
        }

        return area;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();

        int count = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (grid[row][col] != 0){
                    long long area = bfs(grid, row, col);
                    if (area % k == 0){
                        count ++;
                    }
                }
            }
        }
        return count;
    }

};

int main(){
    Solution sol;

    int k = 5;
    vector<vector<int>> grid = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };

    cout << sol.countIslands(grid, k) << endl; // 2

    grid = {
        {0, 0, 0},
        {0, 0, 1},
        {11, 0, 6},
        {0, 10, 2},
        {0, 0, 0},
        {8, 0, 0}
    };

    cout << sol.countIslands(grid, 19) << endl; // 1

}