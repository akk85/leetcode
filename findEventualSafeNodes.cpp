#include "common.hpp"

/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. 

The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes 
adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting 
from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
Intuition:
    topological sort(khans algo)
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjList(n);
        vector<int> indegree(n);
        // build reverse adjacency list 
        for (int i = 0; i < n; i++){
            for (const auto& node : graph[i]){
                adjList[node].push_back(i);
                indegree[i] ++;
            }
        }

        // get nodes with ero indegree
        queue<int> q;
        for (int node = 0; node < n; node ++){
            if (indegree[node] == 0){
                q.push(node);
            }
        }
        vector<bool> safe(n, false);
        while(!q.empty()){
            int node = q.front(); q.pop();
            safe[node] = true;

            for (const auto& neigh : adjList[node]){
                indegree[neigh] --;
                if (indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        vector<int> result;
        for (int node = 0; node < n; node++){
            if (safe[node] == true){
                result.push_back(node);
            }
        }

        return result;
    }
};

void printResult(const vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}
int main(){
    Solution sol;

    vector<vector<int>> graph = {
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> result = sol.eventualSafeNodes(graph); // [2, 4, 5, 6]

    printResult(result);


}