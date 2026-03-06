#include "../common.hpp"

/*
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the minimum number of 0's you must flip to connect the two islands.

Intution:
    1. find on island flip cells to 5 to identify it from other island 
    2. from this island perform a multi level bfs extend to all nghbors and try to flip zero to 1
    3. after each cell increment changes to + 1
    4. if we reach the other island we return current distance 
*/
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q2;
        findFirstIsland(grid, q2);
        int bridges = connectIslands(grid, q2);

        return bridges;
    }
private:
    const vector<pair<int, int>> directions = {{0, -1}, {0, 1},{-1, 0}, {1, 0}};
    void findFirstIsland(vector<vector<int>>& grid, queue<pair<int, int>>& q2){
        int rows = grid.size(), cols = grid[0].size();

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    bfs(grid, q2, row, col);
                    return;
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>> &q2, int r, int c){
        int rows = grid.size(), cols = grid[0].size();

        grid[r][c] = 5;
        queue<pair<int, int>> q1;

        q1.push({r, c});
        q2.push({r, c});

        while (!q1.empty()){
            auto [row, col] = q1.front(); q1.pop();

            for (const auto [dr, dc] : directions){
                int nRow = row + dr;
                int nCol = col + dc;

                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == 1){
                    grid[nRow][nCol] = 5;
                    q1.push({nRow, nCol});
                    q2.push({nRow, nCol});
                }
            }
        }
    }

    int connectIslands(vector<vector<int>>& grid, queue<pair<int, int>>& q){
        int rows = grid.size(), cols = grid[0].size();

        int distance = 0;
        while(!q.empty()){
            int size = q.size();

            for (int i = 0; i < size; i++){
                auto [row, col] = q.front(); q.pop();

                for (const auto [dr, dc] : directions){
                    int nRow = row + dr;
                    int nCol = col + dc;

                    if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == 0){
                        grid[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                    } 
                    else if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == 1){
                        return distance;
                    }
                }
            }
            distance ++;
        }
        return distance;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1,0},
        {0,1}
    };

    cout << sol.shortestBridge(grid) << endl;  // 1

    grid = {
        {0,1,0},
        {0,0,0},
        {0,0,1}
    };

    cout << sol.shortestBridge(grid) << endl;  // 2

    grid = {
        {1,1,1,1,1},
        {1,0,0,0,1},
        {0,1,1,0,1},
        {1,0,0,0,1},
        {1,1,1,1,1}
    };

    cout << sol.shortestBridge(grid) << endl;  // 1

    return 0;
}