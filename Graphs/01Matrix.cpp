#include "../common.hpp"

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
*/
class Solution {
private:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<bool>> visited;
    queue<pair<int, int>> getZeroCells(vector<vector<int>>& mat){
        int rows = mat.size(), cols = mat[0].size();

        queue<pair<int, int>> q;
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (mat[row][col] == 0){
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }

        return q;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();

        visited.resize(rows);
        for (int row = 0; row < rows; row ++){
            visited[row].resize(cols);
        }

        queue<pair<int, int>> q = getZeroCells(mat);
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i ++){
                auto [row, col] = q.front(); q.pop();

                for (const auto [dr, dc] : directions){
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr][nc] == 1 && visited[nr][nc] == false){
                        q.push({nr, nc});
                        mat[nr][nc] = dist; 
                        visited[nr][nc] = true;

                    }
                }
            }
            dist ++;
        }

        return mat;
    }
};

void printMatrix(vector<vector<int>>& mat){
    for (const vector<int>& vec : mat){
        for (const int& val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main(){
    Solution sol;

    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    sol.updateMatrix(mat);
    printMatrix(mat); 

    vector<vector<int>> mat1 = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    sol.updateMatrix(mat1);
    printMatrix(mat1); 

}