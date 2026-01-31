#include "common.hpp"

class Solution{
public:                                   // 0       1
    void bfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col}); //    
        grid[row][col] = '0';

        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();   // (2,0)
/*
      0    1.  2.  3.   4
 0   {'0','0','0','0','0'},
 1   {'0','0','0','0','0'},
 2   {'0','0','0','0','0'},
 3   {'0','0','0','0','0'}
*/
            // left
            int dr = row; // (0, 0)
            int dc = col - 1; 
            if (dc >= 0 and grid[row][dc] == '1'){
                q.push({dr, dc});
                grid[dr][dc] = '0';
            }

            // right
            dr = row;     // (0, 2)
            dc = col + 1;
            if (col < static_cast<int>(grid[0].size()) && grid[dr][dc] == '1'){
                q.push({dr, dc});
                grid[dr][dc] = '0';
            }

            // up 
            dr = row - 1;
            dc = col;
            if (dr >= 0 && grid[dr][dc] == '1'){
                q.push({dr, dc});
                grid[dr][dc] = '0';
            }

            // down 
            dr = row + 1;
            dc = col;
            if (dr < static_cast<int>(grid.size()) && grid[dr][dc] == '1'){
                q.push({dr, dc});
                grid[dr][dc] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid){
        int islands {}; // 1

        int rows = grid.size(); // 4
        int cols = grid[0].size();  // 5 

        for (int row {}; row < rows; ++row){
            for (int col {}; col < cols; ++col){
                char currentPos = grid[row][col]; // 0, 1
                if (currentPos == '1'){
                    bfs(grid, row, col);
                    islands ++;
                }
            }
        }
        return islands;
    }
};

/*
      0    1.  2.  3.   4
 0   {'0','1','1','1','0'},
 2   {'0','1','0','1','0'},
 3   {'1','1','0','0','0'},
 4   {'0','0','0','0','0'}
*/

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
