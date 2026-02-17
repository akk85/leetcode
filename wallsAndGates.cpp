#include "common.hpp"

/*
You are given a  m×n 2D grid initialized with these three possible values:

-1 - A wall or an obstacle 
0 - A gate 
INF - An empty room  that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
Fill each empty room with the distance to its nearest gate. If a an empty room cannot reach a gate then the value should remain INF.

Assume the grid can only be traversed up, down, left, or right.

Modify the grid in-place.

Intuition  

Starting from all gates at once, we treat them as the source of our BFS. 

Since each gate already has distance 0, we expand outward from them level by level.

Each time we visit a neighboring empty room, we update it to be:

    current cell value + 1

That naturally builds the distance layer by layer. Because BFS processes in increasing distance order, 
the first time we reach an empty room is guaranteed to be its shortest distance to a gate.

We continue expanding until the queue is empty. Any room we never reach remains `INF`, meaning it cannot reach a gate.

---
Pseudo code
for each row in grid
    for each col in grid
        if cell == gate
            q.push(cell)   // start BFS from all gates

while queue not empty
    curr = q.front()
    q.pop()

    for each neighbor of curr (up, down, left, right)
        if neighbor in bounds AND neighbor is EMPTYROOM
            grid[neighbor] = grid[curr] + 1
            q.push(neighbor)



*/

#define GATE 0
#define EMPTYROOM 2147483647
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        getGates(grid, q);
        bfs(grid, q);
    }

    void getGates(vector<vector<int>>& grid, queue<pair<int, int>>& q){
        int rows = grid.size();
        int cols = grid[0].size();

        for (int row = 0; row < rows; row++){
            for (int col = 0; col < cols; col++){
                if (grid[row][col] == GATE){
                    q.push({row, col});
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q){
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> directions {{0, -1},  {0,  1}, {-1, 0}, {1,  0} };

        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();
            
            for (const vector<int>& dir : directions){
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == EMPTYROOM){
                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};

void printBoard(vector<vector<int>>& grid){
    for (auto &row : grid) {
        for (int v : row) {
            if (v == 2147483647) cout << "INF\t";
            else cout << v << "\t";
        }
        cout << endl;
    }
}
int main() {
    Solution sol;

    vector<vector<int>> rooms = {
        {2147483647, -1, 0, 2147483647},
        {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},
        {0, -1, 2147483647, 2147483647}
    };

    sol.wallsAndGates(rooms);

    // Print the grid
    printBoard(rooms);

    return 0;
}
