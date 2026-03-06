#include "../common.hpp"

/*
Given a 2D grid consists of 0s (land) and 1s (water).  

An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Intuition:
    1. find the unclosed regions i.e any island that is connectd to the borders and mark the whole island as invalid (5)
    2. now go over the grid again any uninvalidated land cell is valid. mark the whole island as visited and increment count to 1. repeat for whole grid
*/

#define LAND  0
#define VISITED 1
#define INVALID 5

class Solution {
private:
    vector<pair<int, int>> directions {{0, -1},  {0,  1}, {-1, 0}, {1,  0} };
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        captureBorderConnectedRegions(grid);
        int closedRegions = countClosedRegions(grid);

        return closedRegions;
    }

    void captureBorderConnectedRegions(vector<vector<int>>& grid){
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q;
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) && grid[row][col] == LAND){
                    grid[row][col] = INVALID;
                    q.push({row, col});
                }
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (auto [dr, dc] : directions){
                int nRow = row + dr;
                int nCol = col + dc;

                if (nRow >=0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == LAND){
                    grid[nRow][nCol] = INVALID;
                    q.push({nRow, nCol});
                }
            }

        }
    }
    int countClosedRegions(vector<vector<int>>& grid){
        int rows = grid.size(), cols = grid[0].size();

        int islands = 0;
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == LAND){
                    bfs(grid, row, col); // visit entire island and count it as 1
                    islands ++;
                }
            }
        }  

        return islands;
    }

    void bfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});

        grid[r][c] = VISITED;

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (auto [dr, dc] : directions){
                int nRow = row + dr;
                int nCol = col + dc;

                if (nRow >=0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == LAND){
                    grid[nRow][nCol] = VISITED;
                    q.push({nRow, nCol}); // visit its neighbors
                }
            }
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
    };

    cout << sol.closedIsland(grid) << endl; // 2

    grid = {
        {0,0,1,0,0},
        {0,1,0,1,0},
        {0,1,1,1,0}
    };

    cout << sol.closedIsland(grid) << endl; // 1

    grid = {
        {1,1,1,1,1,1,1},
        {1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1},
        {1,0,1,0,1,0,1},
        {1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1},
        {1,1,1,1,1,1,1}
    };

    cout << sol.closedIsland(grid) << endl; // 2

    return 0;
}