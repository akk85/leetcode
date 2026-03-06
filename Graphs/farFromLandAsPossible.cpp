#include "../common.hpp"

/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: 
the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
*/

#define WATER 0
#define LAND  1
class Solution {
private:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<pair<int, int>> getLands(vector<vector<int>>& grid){
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (grid[row][col] == LAND){
                    q.push({row, col});
                }
            }
        }
        return q;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q = getLands(grid);

        int lands = q.size();

        if (q.empty() || lands == rows * cols){
            return -1;
        }
    

        int distance = 0;
        while(!q.empty()){
            int size = q.size();
            bool expanded = false;
            for (int i = 0; i < size; i ++){
               
                auto [row, col] = q.front(); q.pop();

                for (const auto [dr, dc] : directions){
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == WATER){
                        q.push({nr, nc});
                        grid[nr][nc] = LAND;
                        expanded = true;
                    }
                }
            }
            if (expanded){
                distance++;
            }     
        }

        return distance;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };

    cout << sol.maxDistance(grid) << endl; // 2

    grid = {
        {1,0,0},
        {0,0,0},
        {0,0,0}
    };

    cout << sol.maxDistance(grid) << endl; // 4
}