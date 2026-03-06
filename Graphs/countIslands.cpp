#include "../common.hpp"

/*
Thought process:
    1. for each cell in grid, if cell is water start a bfs in this cell mark all its lands as 0 and increment count
*/

#define LAND '1'
#define VISITED '0'
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        int islands = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == LAND){
                    bfs(grid, row, col);
                    islands ++;
                }
            }
        }

        return islands;
    }
private:
    const vector<vector<int>> directions = {{0, -1}, {0, 1},{-1, 0}, {1, 0}};
    void bfs(vector<vector<char>>& grid, int row, int col){
        int rows = grid.size(), cols = grid[0].size();
        grid[row][col] = VISITED;
        queue<pair<int, int>> q;

        q.push({row, col});

        while (!q.empty()){
            auto [row , col] = q.front(); q.pop();

            for (const vector<int>& dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == LAND){
                    grid[nr][nc] = VISITED;
                    q.push({nr, nc});
                }
            }
        }
        return;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {
                                {'0','1','1','1','0'},
                                {'0','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}
                                };

    cout << sol.numIslands(grid) << endl; // 1


    grid = {
                                {'1','1','0','0','1'},
                                {'1','1','0','0','1'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}
                                };

     cout << sol.numIslands(grid) << endl;  // 4
}