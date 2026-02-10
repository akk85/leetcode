#include "common.hpp"

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
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(); int COLS = grid[0].size();
        int islands {};
        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (grid[r][c] == '1'){
                    islands++;
                    bfs(grid, r, c);
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<char>>& grid, int row, int col){
        int ROWS = grid.size(); int COLS = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            //left
            int nr = row; int nc = col - 1;
            if (nc >= 0 && grid[nr][nc] == '1'){
                q.push({nr, nc});
                grid[nr][nc] = '0';
            }

            //right
            nr = row; nc = col + 1;
            if (nc < COLS && grid[nr][nc] == '1'){
                q.push({nr, nc});
                grid[nr][nc] = '0'; 
            }

            //up
            nr = row - 1; nc = col;
            if (nr >= 0 && grid[nr][nc] == '1'){
                q.push({nr, nc});
                grid[nr][nc] = '0';
            }
            //down
            nr = row + 1; nc = col;
            if (nr < ROWS && grid[nr][nc] == '1'){
                q.push({nr, nc});
                grid[nr][nc] = '0';
            }
        }
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

    cout << sol.numIslands(grid) << endl;


    grid = {
                                {'1','1','0','0','1'},
                                {'1','1','0','0','1'},
                                {'0','0','1','0','0'},
                                {'0','0','0','1','1'}
                                };

     cout << sol.numIslands(grid) << endl;
}


