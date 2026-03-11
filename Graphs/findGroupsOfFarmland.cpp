#include "../common.hpp"

/*
You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. 
These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to 
another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). 
Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a 
bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, 
return an empty array. You may return the answer in any order.

Thought process:
    scan through entire grid, for each land cell start bfs from it, initialize [r1, c1, r2, c2] with this cell
    r1 and c1 will be by default this node
    for r2 and c2 as we scan through entire farmland update them with a row or column that is bigger than the current r2 and c2 by the end 
    we will have r2 and c2 containing bottom right which is infact the biggest row and biggest column config in this farmland connection
*/

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size(), cols = land[0].size();

        vector<vector<int>> result;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (land[row][col] == 1){
                    vector<int> farmland = bfs(land, row, col);
                    result.push_back(farmland);
                }
            }
        }
        return result;
    }
private:
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<int> bfs(vector<vector<int>>& land, int row, int col){
        int rows = land.size(), cols = land[0].size();
        int r1 = row, c1 = col;
        int r2 = row, c2 = col;

        queue<pair<int, int>> q;
        q.push({row, col});
        land[row][col] = 0; // visited

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for (const auto& [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && land[nr][nc] == 1){
                    r2 = max(r2, nr);
                    c2 = max(c2, nc);
                    q.push({nr, nc});
                    land[nr][nc] = 0; // visited
                }
            }
        }

        return {r1, c1, r2, c2};
    }
};

void printVector(vector<vector<int>>& result){
    for (const vector<int>& vec : result){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<vector<int>> land = {
        {1,0,0},
        {0,1,1},
        {0,1,1}
    };

    vector<vector<int>> result = sol.findFarmland(land); // [[0,0,0,0],[1,1,2,2]]
    printVector(result);

    land = {
        {1,1},
        {1,1}
    };
    result = sol.findFarmland(land);      // [[0,0,1,1]]

    printVector(result);
    land = {
        {0}
    };
    result = sol.findFarmland(land);   // []
    printVector(result);
}