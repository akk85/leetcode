#include "../common.hpp"


class Solution{
public:   
    int countComponents(int n, vector<vector<int>>& edges){
        vector<vector<int>> adjList(n);
        for (const vector<int>& edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        vector<bool> visited(n, false);
        int components {};
        for (int node = 0; node < n; node++){
            if (!visited[node]){
                bfs(adjList, visited, node);
                components ++;
            }
        }

        return components;
    }

    void bfs(vector<vector<int>>& adjList, vector<bool>& visited, int node){
        queue<int> q;
        q.push(node);

        visited[node] = true;
        while(!q.empty()){
            int node = q.front(); q.pop();
            for (int neighbor: adjList[node]){
                if (!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    
};
/*
0 - 1
1 - 0, 2
2 - 1
3 - 4
4 - 3
*/
int main(){
    Solution sol;

    int n = 5;
    vector<vector<int>> edges = {
                {0, 1},               
                {1, 2},
                {3, 4}
    };

    cout << sol.countComponents(n, edges) << endl;

    edges = {
                {0, 1},
                {1, 2},
                {2, 3},
                {3, 4}
    };

    cout << sol.countComponents(n, edges) << endl;
}