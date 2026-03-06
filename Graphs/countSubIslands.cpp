#include "../common.hpp"

/*
Thought process:
    1. for each island in grid2 check if all cells are lands in grid1 and increent counter if so 
    2. repaeat for each islands 
*/

#define LAND 1
#define VISITED 0
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid2.size(), cols = grid2[0].size();

        int count = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col++){
                if (grid2[row][col] == LAND){
                    bool isSubIsland = checkIslandCells(grid1, grid2, row, col);
                    if (isSubIsland) count ++;
                }
            }
        }

        return count;
    }
private:
    const vector<vector<int>> directions = {{0, -1}, {0, 1},{-1, 0}, {1, 0}};
    bool checkIslandCells(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col){
        int rows = grid2.size(), cols = grid2[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        grid2[row][col] = VISITED;

        bool isSubIsland = true;
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            
            if (grid1[row][col] != LAND) isSubIsland = false;

            for (const vector<int>& dir : directions){
                int nRow = row + dir[0];
                int nCol = col + dir[1];

                if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid2[nRow][nCol] == LAND){
                    q.push({nRow, nCol});
                    grid2[nRow][nCol] = VISITED;
                }
            }
        }

        return isSubIsland;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1,1,1,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {1,0,0,0,0},
        {1,1,0,1,1}
    };

    vector<vector<int>> grid2 = {
        {1,1,1,0,0},
        {0,0,1,1,1},
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,1,0}
    };

    cout << sol.countSubIslands(grid1, grid2) << endl;  // Expected: 3

    grid1 = {
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {1,1,1,1,1},
        {1,0,1,0,1}
    };
    
    grid2 = {
        {0,0,0,0,0},
        {1,1,1,1,1},
        {0,1,0,1,0},
        {0,1,0,1,0},
        {1,0,0,0,1}
    };

    cout << sol.countSubIslands(grid1, grid2) << endl;  // Expected: 2

    return 0;
}