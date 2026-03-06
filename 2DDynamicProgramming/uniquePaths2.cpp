#include "../common.hpp"

/*
You are given an m x n integer array grid. 

There is a robot initially located at the top-left corner (i.e., grid[0][0]). 

The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 

The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

*/

#define OBSTACLE 1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();

        // no path if source or destination is an obstacle 
        if (obstacleGrid[0][0] || obstacleGrid[rows - 1][cols - 1]) return 0;

        vector<vector<int>> paths(rows);
        for (int vec = 0; vec < rows; vec++){
            paths[vec].resize(cols);
        }

        // bottom row 
        bool obstacleSeen = false;
        for (int col = cols - 1; col >=0; col --){
            if (obstacleGrid[rows - 1][col] == OBSTACLE) obstacleSeen = true;
            if (!obstacleSeen) paths[rows - 1][col] = 1;
            else paths[rows - 1][col] = 0;
        }

        // right column 
        obstacleSeen = false;
        for (int row = rows - 1; row >= 0; row --){
            if (obstacleGrid[row][cols - 1] == OBSTACLE) obstacleSeen = true;
            if (!obstacleSeen) paths[row][cols - 1] = 1;
            else paths[row][cols - 1] = 0;
        }


        // build path grid if any middle cell is an obstacle path == 0
        for (int row = rows - 2; row >= 0; row --){
            for (int col = cols - 2; col >= 0; col --){
                if (obstacleGrid[row][col] == OBSTACLE) paths[row][col] = 0;
                else {
                    int rightCell   = paths[row][col + 1];
                    int bottomCell  = paths[row + 1][col];

                    paths[row][col] = rightCell + bottomCell;
                }

            }
        }

        return paths[0][0];
    }
};

int main(){
    Solution sol;

    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl; // 3

    obstacleGrid = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}
    };

    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl; // 0

    obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl; // 2

    obstacleGrid = {
        {0, 1},
        {0, 0}
    };

    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl; // 1
}