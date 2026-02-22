#include "common.hpp"

/*
Thought process:
    1. Keep track of how many servers in each row and each column
    2. Iterate over grid and for each server check if its row / col has a server in it and increment count if so
*/
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> rowCount(rows, 0);
        vector<int> colCount(cols, 0);

        servers(grid, rowCount, colCount);
        int res = checkConnection(grid, rowCount, colCount);

        return res;
       
    }
private:
    void servers(vector<vector<int>>& grid, vector<int>& rowCount, vector<int>& colCount){
        int rows = grid.size(), cols = grid[0].size();
        
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1){
                    rowCount[row] ++;
                    colCount[col] ++;
                }
            }
        }
        return;
    }

    int checkConnection(vector<vector<int>>& grid, vector<int>& rowCount, vector<int>& colCount){
        int rows = grid.size(), cols = grid[0].size();

        int count = 0;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == 1 && (rowCount[row] > 1 || colCount[col] > 1)){
                    count += 1;
                }
            }
        }

        return count;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {1,1,0,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,1}
    };

    cout << sol.countServers(grid) << endl; // 4
}