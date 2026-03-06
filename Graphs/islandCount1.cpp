#include "../common.hpp"

class Solution{
public:
    
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& visited, int row, int col){
        queue<pair<int, int>> q;
        q.push({row, col});

        visited[row][col] = true;

        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();

            // left
            int dr = row;
            int cr = col - 1;
            if (cr >= 0 && grid[dr][cr] == '1' && !visited[dr][cr]){
                q.push({dr, cr});
                visited[dr][cr] = true;
            }

            // right
            dr = row;
            cr = col + 1;
            if (cr < grid[0].size() && grid[dr][cr] == '1' && !visited[dr][cr]){
                q.push({dr, cr});
                visited[dr][cr] = true;
            }

            // up
            dr = row - 1;
            cr = col;
            if (dr > 0 && grid[dr][cr] == '1' && !visited[dr][cr]){
                q.push({dr, cr});
                visited[dr][cr] = true;
            }

            // down
            dr = row + 1;
            cr = col;
            if (dr < grid.size() && grid[dr][cr] == '1' && !visited[dr][cr]){
                q.push({dr, cr});
                visited[dr][cr] = true;
            }
        }
    }


    int numIslands(vector<vector<char>>& grid){
    int islands {};
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row {}; row < rows; ++row){
            for (int col {}; col < cols; ++col){
                char currentPos = grid[row][col];
                if (currentPos == '1' && !visited[row][col]){
                    bfs(grid, visited, row, col);
                    islands++;
                }
            }
        }

        return islands;
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