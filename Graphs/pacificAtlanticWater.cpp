#include "../common.hpp"
#include <set>

/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


Thought process:
    1. I will explore pacific and atlantic separately
    2. starting with pacific mark all the cells bordering pacific as possible to reach. 
    3. from each of this cell, do a bfs search for each cell exploring neighbors to see if onto what cell can water 
        flow from pacific to this cell which is just checking if neighbor cell is greater or equal to neighbor cell
        any possible cell throw it into a pacific set
    4. repeat this bfs search again on the grid doing the same for atlantic
    5. finally explore the two sets and see which cells are in both the pacific and the atlatic set and return them

Time -> -> we traverse each cell once in the whole graph therefore O(n) and for each cell we do a set operation 
    each insertion and lookup operation in set is O(logn) since an ordered map is set up as a black tree(binary treee) 
    and for m * n cells this is log(m * n) overall complexity is O(m*nlog(m*n))
Space -> 0(m*n) 
    
pseudo code
    mark all border cells bodering ocean as visited 
    for each cell in border:
        perform a bfs call 
    
    bfs function
        starting with this cell in queue;
        for each neighbor if neighbor not visited and water can flow to it:
            mark as visited
            push to queue to explore its neighbors as well

    repeat above for atlantic ocean

    return cell in pacific set and in atlatinc set 
    
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int, int>> pacific;
        set<pair<int, int>> atlantic;
        vector<vector<int>> common;

        vector<pair<int, int>> pacificBorder;
        vector<pair<int, int>> atlanticBorder;

        int rows = heights.size();
        int cols = heights[0].size();

        // get border cells for pacific -> top row and left column
        for (int col = 0; col < cols; col++){
            int row = 0;
            pacificBorder.push_back({row, col});
        }

        for (int row = 0; row < rows; row++){
            int col = 0;
            pacificBorder.push_back({row, col});
        }

        // get border cells for atlantic -> bottow row and right column
        for (int col = 0; col < cols; col++){
            int row = rows - 1;
            atlanticBorder.push_back({row, col});
        }

        for (int row = 0; row < rows; row++){
            int col = cols - 1;
            atlanticBorder.push_back({row, col});
        }

        // perform bfs call to all cells in the border
        bfs(heights, pacificBorder,  pacific);
        bfs(heights, atlanticBorder, atlantic);

        for (const auto& cell : pacific){
            if (atlantic.contains(cell)){
                auto [row, col] = cell;
                common.push_back({row, col});
            }
        }

        return common;
    }

    void bfs(vector<vector<int>>& heights, vector<pair<int, int>>& borderCells, set<pair<int, int>>& visited){
        int rows = heights.size();
        int cols = heights[0].size();
        queue<pair<int, int>> q;
        // for all border cells mark as visited and push to queue for processing their neighbors
        for (const pair cell : borderCells){
            visited.insert(cell);
            q.push(cell);
        }

        //start bfs 
        while (!q.empty()){
            auto [row, col] = q.front(); q.pop();

            // for this cell check if water can flow to its neighbor if so add to result and push to queue to vists its neighbors as well
            int directions[4][2] = {
                                            {0, -1},
                                            {0, 1},
                                            {1, 0},
                                            {-1, 0},
            };

            int nr {};
            int nc {};

            for (auto& dir : directions){
                nr = row + dir[0];
                nc = col + dir[1];

                if (nr >=0 && nr < rows && nc >= 0 && nc < cols && !visited.contains({nr, nc}) && heights[row][col] <= heights[nr][nc]){
                    visited.insert({nr, nc});
                    q.push({nr, nc});
                }
            }
            
        }
    }

    void print2DVector(const vector<vector<int>>& matrix) {
        for (const auto& row : matrix) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    vector<vector<int>> result = sol.pacificAtlantic(heights);

    
    sol.print2DVector(result);

}