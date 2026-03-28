#include "../common.hpp"

/*
You are given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. 
You spend one second to walk over one edge of the tree. 
Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices a[i] and b[i]. 
Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);

        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);

            indegree[node1] ++;
            indegree[node2] ++;
        }

        queue<int> q;
        for (int node = 1; node < n; node ++){
            if (indegree[node] == 1) {
                q.push(node);
            }
        }
        
        vector<int> cost(n, 0);
        while(!q.empty()){
            int node = q.front(); q.pop();
            indegree[node] --;

            for (const int& neighbor : adjList[node]){
                if (indegree[neighbor] == 0) continue;
                
                indegree[neighbor] --;
                if (cost[node] != 0|| hasApple[node]){
                    cost[neighbor] += cost[node] + 2;
                }

                if (indegree[neighbor] == 1 && neighbor != 0){
                    q.push(neighbor);
                }
            }
        }

        return cost[0];
    }
};