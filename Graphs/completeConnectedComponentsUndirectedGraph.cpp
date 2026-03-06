#include "../common.hpp"

/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

Thought Intuition:
    for each unvisited node:
        start a bfs and visit the whole component
        during bfs keep track of number of edges where edges for each node is just the size of its adjacency list vector
        and count all nodes reached in this bfs traversal.
        for a complete component edges = nodes * (nodes - 1) / 2 return true if expected edges == number of edges counted in component 
*/

class Solution {
private:
    vector<bool> visited;
    bool bfs(vector<vector<int>>& adjList, int node){
        int edges = 0;
        int nodes = 0;
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()){
            int currNode = q.front(); q.pop();

            edges += adjList[currNode].size(); nodes += 1;
            for (const int& neighbor : adjList[currNode]){

                if (visited[neighbor] == false){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        int expectedEdges = nodes * (nodes - 1) / 2;

        if (edges / 2 == expectedEdges){ // I divide by 2 since in undirected we count twice edges for each node
            return true;
        }

        return false;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        visited.resize(n, false);

        for (const vector<int>& edge : edges){
            int node1 = edge[0], node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }

        int complete = 0;
        for (int node = 0; node < n; node ++){
            if (visited[node] == false){
                bool isConnected = bfs(adjList, node);
                if (isConnected){
                    complete += 1;
                }
            }
        }

        return complete;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {1,2},
        {3,4},
        {3,5}
    };

    cout << sol.countCompleteComponents(6, edges) << endl; // 1
}