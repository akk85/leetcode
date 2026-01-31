#include "common.hpp"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    return bfs(grid, row, col);
                }
            }
        }
        return 0; // no island 
    }


    int bfs(vector<vector<int>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});

        grid[row][col] = -1;     // visited

        int directions[4][2] = {
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0},
        };  

        int perimeter {};
        while (!q.empty()){
            auto [r, c] = q.front(); q.pop();

            // check neighbors
            for(auto& dir : directions){
                int nr = r + dir[0];
                int nc = c + dir[1];
                // left col - 1 right col + 1 up row - 1 down row + 1
                if (nc < 0 || nc >= static_cast<int>(grid[0].size()) ||
                    nr < 0 || nr >= static_cast<int>(grid.size()))    {
                    perimeter ++;                 // boundaries
                } else if (grid[nr][nc] == 0) {       // water
                    perimeter ++;
                } else if (grid[nr][nc] == 1) { // land 
                    q.push({nr, nc});
                    grid[nr][nc] = -1;     // mark as visited land
                }   
            }
        }
        return perimeter;
    }
/*
For every cell (r, c):

If grid[r][c] == 1:

perimeter += 4

If top neighbor is land → perimeter--

If bottom neighbor is land → perimeter--

If left neighbor is land → perimeter--

If right neighbor is land → perimeter--
*/
    int islandPerimeterSimple(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();

        int perimeter {};
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    perimeter += 4;
                
                    if (col > 0 && grid[row][col - 1] == 1) perimeter --; // left
                    if (col < cols - 1 && grid[row][col + 1] == 1) perimeter --; // right
                    if (row > 0 && grid[row - 1][col] == 1) perimeter --; // up
                    if (row < rows - 1 && grid[row + 1][col] == 1) perimeter --; // down
                }
            }
        }
        return perimeter;
    }
        
};


int main(){
    Solution sol;
    vector<vector<int>> grid = {
                            {1,1,0,0},
                            {1,0,0,0},
                            {1,1,1,0},
                            {0,0,1,1}
                        };
    cout << sol.islandPerimeter(grid) << endl;
    
    
    grid = {
            {1,1,0,0},
            {1,0,0,0},
            {1,1,1,0},
            {0,0,1,1}
        }; 
    cout << sol.islandPerimeterSimple(grid) << endl;

    
    
    grid = {
        {1, 0}
    };
    cout << sol.islandPerimeter(grid) << endl;
    
    
    grid = {
        {1, 0}
    };
    cout << sol.islandPerimeterSimple(grid) << endl;

}