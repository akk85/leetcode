#include "../common.hpp"
/*

You are given a 2-D matrix grid. Each cell can have one of three possible values:

0 representing an empty cell
1 representing a fresh fruit
2 representing a rotten fruit
Every minute, if a fresh fruit is horizontally or vertically adjacent to a rotten fruit, then the fresh fruit also becomes rotten.

Return the minimum number of minutes that must elapse until there are zero fresh fruits remaining. If this state is impossible within the grid, return -1.

Intuition
    1. Any rotten orange spreads rot to its 4 neighbors (up, down, left, right) each minute.
    2. All rotten oranges can act simultaneously, so we start BFS from all rotten oranges at once.
    3. Use BFS layer by layer, where each layer corresponds to 1 minute.
    4. Keep track of fresh oranges remaining. Stop when either:
        * All fresh oranges are rotten → return total minutes
        * No more fresh oranges can be infected → return -1
    5. Mark infected oranges as rotten to avoid revisiting them.

initialize queue q
initialize freshOranges = 0

for each cell in grid:
    if cell is rotten:
        q.push(cell)        // start BFS from all rotten oranges
    else if cell is fresh:
        freshOranges += 1   // count fresh oranges

if freshOranges == 0:
    return 0                // nothing to infect

minutes = 0
directions = [(0,-1), (0,1), (-1,0), (1,0)]  // left, right, up, down

while q is not empty:
    size = q.size()
    infectedThisRound = false
    for i = 0 to size-1:
        curr = q.pop()
        for dir in directions:
            neighbor = curr + dir
            if neighbor is in bounds and is fresh:
                mark neighbor as rotten
                q.push(neighbor)
                freshOranges -= 1
                infectedThisRound = true
    if infectedThisRound:
        minutes += 1

if freshOranges == 0:
    return minutes
else:
    return -1

Time -> 0(m*n) Space is 0(m*n) incase all oranges are rotten 

*/

#define orange 1
#define rotten 2

class Solution {
private:
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;

        int freshOranges =  getRottenOranges(grid, q);

        if (freshOranges == 0) return 0;

        int minutes = bfs(grid, q, freshOranges);

        if (freshOranges == 0) return minutes;
        
        return -1;
    }

    int getRottenOranges(vector<vector<int>>& grid, queue<pair<int, int>>& q){
        int freshOranges = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == rotten){
                    q.push({row, col});
                }
                else if (grid[row][col] == orange){
                    freshOranges += 1;
                }
            }
        }

        return freshOranges;
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& freshOranges){
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> directions {{0, -1},  {0,  1}, {-1, 0}, {1,  0} };

        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            bool infectedThisRound = false;
            for (int i = 0; i < size; i++){
                auto [row, col] = q.front(); q.pop();

                for (const vector<int>& dir : directions){
                    int nr = row + dir[0];
                    int nc = col + dir[1];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == orange){
                        grid[nr][nc] = rotten;
                        q.push({nr,nc});
                        freshOranges --;
                        infectedThisRound = true;
                    }
                }

            }
            if (infectedThisRound) minutes++;
        }
        return minutes;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> grid = {
        {1, 1, 0},
        {0, 1, 1},
        {0, 1, 2},
    };

    cout << sol.orangesRotting(grid) << endl;   // 4

    grid = {
        {1, 0, 1},
        {0, 2, 0},
        {1, 0, 1},
    };

    cout << sol.orangesRotting(grid) << endl; // -1

    grid = {
        {1, 1, 0},
        {0, 1, 0},
        {1, 1, 2},
    };

    cout << sol.orangesRotting(grid) << endl; // 4

    grid = {
        {2,1,1},
        {1,1,1},
        {0,1,2},
    };

    cout << sol.orangesRotting(grid) << endl; // -1

}
/*
[2,1,1],
[1,1,1],
[0,1,2]

*/