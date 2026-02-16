#include "common.hpp"
#include <set>
/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

Thought process:
    run bfs assigning unique ids for each island
    run bfs again and for each zero sum up all the connecting islands to its 4 directions + 1 itself 
    return the maxIsland

    since we can have a grid with no zero we can keep our running maxIsland as maximum island from the 1st bfs and update it accordingly from second bfs run

    pseudo code:
        int id = 2
        for each row in rows
            for each col in cols
                if grid[row][col] is land 
                    bfs(grid, row, col)

        bfs(grid, row, col)
            queue.push(row,col)
            grid[row][col] = id
            row col visited
            while q not empty
                row col = q.front
                for each dir in directions
                    if new cell is land
                        grid[cell] = id
                        q.push(cell)
                        mark cell visited
            change id to +1 
            return;

        // second bfs call
        maxIsland = max of all unique id islands 
        for each row in rows
            for each col in cols
                if grid[row][col] is water
                    int currIsland = check4nighbors(grid,row,col)
                    maxIsand = max(maxIsland, currIsland)

        return maxIsland

        int check4nighbors(grid, row, col)
            cell = row col
            get left right up down neighbor id
            sum up all neighbor id islands value + 1(itself)

            return sum

1 0
0 1 

2 0
0 3 

1 + 1 + 1 = 3

2 2 2 0 0
2 2 2 0 3
0 0 0 0 3 
3 3 3 3 3

6 + 7 = 14 
*/

class Solution {
public:
    int water    = 0;
    int land     = 1;
    vector<vector<int>> directions = {
        {0, -1},  // left
        {0,  1},  // right
        {-1, 0},  // up
        {1,  0},  // down
    };
    int largestIsland(vector<vector<int>>& grid) {
        int maxIslandArea = 0;
        unordered_map<int, int> IslandsMap;
        int uniqueID = 2;
        int rows = grid.size();
        int cols = grid[0].size();

        // First bfs to mark all islands
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if (grid[row][col] == land){
                    bfs(grid, IslandsMap, maxIslandArea, row, col, uniqueID);
                    uniqueID++;
                }
            }
        }

        // Second run to flip zeros
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if (grid[row][col] == water){
                    int currIsland = check4Directions(grid, IslandsMap, row, col);
                    maxIslandArea = max(maxIslandArea, currIsland);
                }
            }
        }
        return maxIslandArea;
    }

    int check4Directions(vector<vector<int>>& grid, unordered_map<int, int>& IslandsMap, int row, int col){
        int rows = grid.size();
        int cols = grid[0].size();
        int areaSize = 0;
        unordered_set<int> seen;
        for (const vector<int>& dir : directions){
            int nr = row + dir[0];
            int nc = col + dir[1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != water){
                int island = grid[nr][nc];
                if (!seen.contains(island)){
                    int islandSize = IslandsMap[island];
                    areaSize += islandSize;
                    seen.insert(island);
                }
            }
        }

        return areaSize + 1;
    }

    void bfs(vector<vector<int>>& grid, unordered_map<int, int>& IslandsMap, int& maxIslandArea, int row, int col, int id){
        int rows = grid.size();
        int cols = grid[0].size();
        int area = 1;
        queue<pair<int, int>> q;
        grid[row][col] = id;
        q.push({row, col});
        
        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();
            
            for (const vector<int>& dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == land){
                    area ++;
                    grid[nr][nc] = id;
                    q.push({nr,nc});
                }
            }
        }
        IslandsMap[id] = area;
        maxIslandArea = max(maxIslandArea, area);
    }
};
           

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {1,0},
        {0,1}
    };

    cout << sol.largestIsland(grid) << endl;

    grid = {
        {1,0},
        {1,1}
    };

    cout << sol.largestIsland(grid) << endl;

    grid = {
        {1,1},
        {1,1}
    };

    cout << sol.largestIsland(grid) << endl;
}