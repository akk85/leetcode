#include "../common.hpp"


class Solution{
public:
    int minAreaOfIsland(vector<vector<int>>& grid){
    
        int rows = grid.size();
        int cols = grid[0].size();

        int minIslands = INT_MAX;
        
        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    int islands = bfs(grid, row, col);     //find islands 
                    minIslands = min(minIslands, islands);
                }
            }
        }
        
        if (minIslands == INT_MAX){
            minIslands = 0;
        }

        return minIslands;

    }

    int bfs(vector<vector<int>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});
        int lands = 1;
        grid[row][col] = 0;     //visited

        int directions[4][2] = {
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0},
        }; 
        
        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();

            // check neighbors
            for (auto& dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr >= 0 && nr < static_cast<int>(grid.size()) &&
                    nc >= 0 && nc < static_cast<int>(grid[0].size()) && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = 0;
                        lands ++;
                    }
            }
     
        }
        return lands;
    }
};


int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    cout << sol.minAreaOfIsland(grid) << endl;

    grid = {
        {0,0,0,0,0,0,0,0}
    };

    cout << sol.minAreaOfIsland(grid) << endl;
}