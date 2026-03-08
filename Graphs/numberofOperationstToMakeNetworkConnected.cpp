#include "../common.hpp"

/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Thought process:
    Use bfs to find number of connected components
        if node unvisited, do bfs visit all other nodes and mark them as visited incrememnt count 
    if edges - 1 < nodes return -1 impossible for a connection using available cables given 
    return count - 1 
*/

class Solution {
private:
    vector<bool> visited;
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for (const vector<int>& edge : connections){
            int node1 = edge[0], node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }

        visited.assign(n, false);
        int components = 0;
        for (int node = 0; node < n; node ++){
            if (!visited[node]){
                bfs(adjList, node);
                components ++;
            }
        }

        int cables = connections.size();

        if (cables < n - 1){
            return -1;
        }

        int minimumCables = components - 1;
        return minimumCables;

    }

    void bfs(vector<vector<int>>& adjList, int node){
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int current = q.front(); q.pop();

            for (const int neighbor : adjList[current]){
                if (!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main(){
    Solution sol;

    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {1,2}
    };

    cout << sol.makeConnected(4, edges) << endl; // 1

    edges = {
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {1,3}
    };

    cout << sol.makeConnected(6, edges) << endl; // 2
}