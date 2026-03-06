#include "../common.hpp"

class Solution {
private:
    vector<vector<int>> adjList;
    void resizeAdjList(vector<vector<int>>& adjList, int n){
        adjList.resize(n);
    }

    void buildAdjacencyList(vector<vector<int>>& grid){
        int rows = grid.size(); int cols = grid[0].size();

        resizeAdjList(adjList, rows);
        for (int row = 0; row < rows; row ++){
            for (int col = 0; col < cols; col ++){
                if (grid[row][col] == 1){
                    adjList[row].push_back(col);
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, unordered_set<int>& visited, int city){
        queue<int> q;
        visited.insert(city);

        q.push(city);
        
        while(!q.empty()){
            int node = q.front(); q.pop();

            for (const int& connectCity : adjList[node]){
                if (!visited.contains(connectCity)){
                    visited.insert(connectCity);
                    q.push(connectCity);
                }
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        buildAdjacencyList(isConnected);

        int provinces = 0;
        unordered_set<int> visited;
        for (int city = 0; city < n; city ++){
            if (!visited.contains(city)){
                bfs(isConnected, visited, city);
                provinces ++;
            }
        }

        return provinces;
    }
};