#include "../common.hpp"

/*
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

thouhgt process;
    1. i can explore all cells in the grid
        * if cell is water start a bfs call from this cell to explore  and catch all other fish in the water neighboring this cell
        * update our max fish with this number if we caught more fish than from other cells
        * do so for all cells that are water and have not been explored yet
        * 
pseudo code
    for each row in rows
        for each col in cols
            cell = grid[row][col]
            if cell is water and not visited 
                start bfs
                currentfish = fish from bfs
                maxfish = max(maxfish, currentfish)

    int bfs helper function
        fish = 0
        queue push(cell)
        mark cell visited
        while queue not empty explroe neigh
            curr cell = q.pop()
            for (neighbor in neighbors of this cell)
                if neighbor not visited and is water
                    fish += neighbor fish
                    neighbor.visted true 
                    queue.push(neighbor)

        return fish
*/


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();  

        int land = 0;
        int maxFish {};
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                int cell = grid[row][col];

                if (cell != land){
                    int currentFish = bfs(grid, row, col);
                    maxFish = max(maxFish, currentFish);
                }
            }
        }

        return maxFish;
    }

    int bfs(vector<vector<int>>& grid, int row, int col){
        int land = 0;
        int fish = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        fish += grid[row][col];
        q.push({row, col});
        grid[row][col] = 0;  // visited

        vector<pair<int,int>> directions = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            int nr {};
            int nc {};

            for (const pair<int, int> dir : directions){
                nr = row + dir.first;
                nc = col + dir.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != land){
                    int gridFish = grid[nr][nc];
                    fish += gridFish;
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                }
            }

        }

        return fish;
    }   
}; 

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {0, 2, 1, 0},
        {4, 0, 0, 3},
        {1, 0, 0, 4},
        {0, 3, 2, 0}
    };

    cout << sol.findMaxFish(grid) << endl;

    grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 1}
    };

    cout << sol.findMaxFish(grid) << endl;
}