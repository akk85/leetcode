#include "common.hpp"


/*
Thought process:
    1. build adjency list
    2. iterating over all of the nodes from 0 - n nodes, starting from node 0 do a bfs call on this node and visit all the other nodes 
    connected to this node
    3. do this for all nodes and whenver we encounter a node a not visited incrememt component count

*/
class Solution {
public:
    
    int countComponents(int n, vector<vector<int>>& edges) {
        // 1. Build adjacency list for all nodes
        vector<vector<int>> adjList(n);
        for (const vector<int>& edge: edges){
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }

        // 2. Starting from node 0 visit all connected nodes and increment count repeat till nth node
        int components {};
        unordered_set<int> visited;
        for (int node = 0; node < n; node++){
            if (!visited.contains(node)){
                components ++;
                bfs(adjList, visited, node);
            }
        }
        return components;
    }

    void bfs(vector<vector<int>>& adjList, unordered_set<int>& visited, int node){
        queue<int> q;
        q.push(node);
        visited.insert(node);

        while(!q.empty()){
            int currNode = q.front(); q.pop();
            for (const int& neighbor : adjList[currNode]){
                if (!visited.contains(neighbor)){
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
};

int main(){
    Solution sol;

    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {3,4}
    };

    cout << sol.countComponents(5, edges) << endl; // 2

    edges = {
        {0,1},
        {1,2},
        {2,3},
        {3,4}
    };

    cout << sol.countComponents(5, edges) << endl; // 1
}


