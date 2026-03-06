#include "../common.hpp"

/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list 
where edges[i] = [a, b] is an undirected edge connecting the nodes a and b 
with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end 
and return its success probability.

If there is no path from start to end, return 0. 
Your answer will be accepted if it differs from the correct answer by at most 1e-5.


*/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // build adjacency list
        vector<vector<pair<int, double>>> adjList(n); // node -> nei, prob 
        int size = edges.size();
        for (int i = 0; i < size; i++){
            int node1 = edges[i][0]; int node2 = edges[i][1];
            double prob  = succProb[i];

            adjList[node1].push_back({node2, prob});
            adjList[node2].push_back({node1, prob});
        }

        vector<int> nodePathProbability(n, INT_MAX);
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, start_node});

        while(!maxHeap.empty()){
            auto [prob, node] = maxHeap.top(); maxHeap.pop();

            if (node == end_node){
                return prob;
            }

            nodePathProbability[node] = prob;

            for (const auto& [neighNode, neighProb] : adjList[node]){
                if (nodePathProbability[neighNode] == INT_MAX){
                    maxHeap.push({prob * neighProb, neighNode});
                }
            }
        }

        return 0; // zero if no path btwn src and dst 

    }
};

int main(){
    Solution sol;

    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb   = {0.5,0.5,0.2};

    cout << sol.maxProbability(3, edges, succProb, 0, 2) << endl; // 0.25

    edges = {{0,1},{1,2},{0,2}};
    succProb   = {0.5,0.5,0.3};

    cout << sol.maxProbability(3, edges, succProb, 0, 2) << endl; // 0.30
}