#include "common.hpp"

/*
You are given a directed, weighted graph with n vertices labeled from 0 to n - 1 and m edges. Each edge has a non-negative weight.

Given a source vertex src, compute the shortest distance from src to every other vertex in the graph.

If a vertex is unreachable from src, return -1 for that vertex.

Input

n — number of vertices

edges — list of edges, where each edge is represented as:
[u, v, w] meaning there is a directed edge from u to v with weight w

src — source vertex

Output

An array dist of size n, where:

dist[i] = shortest distance from src to vertex i

dist[i] = -1 if i is unreachable

n = 5
start end weight 
edges = [
  [0,1,4],
  [0,2,1],
  [2,1,2],
  [1,3,1],
  [2,3,5],
  [3,4,3]
]
src = 0

[0, 3, 1, 4, 7]

node weight 
0 : (1,4) (2,1)

1 : (3,1) 
2 : (1,2) (3,5)
3 : (4,3)

minHeap =    7,1


weight, node =1, 2


map 
0 0
1 4
2 1 
*/
class Solution{
private:
public:
    vector<long long> dijkstra(vector<vector<int>>& edges, int src, int n){
        // build adjlist
        vector<vector<pair<int, int>>> adjList(n);
        for (const vector<int>& edge : edges){
            int srcNode = edge[0], dstNode = edge[1], weight = edge[2];
            adjList[srcNode].push_back({dstNode, weight});
        }
        
        // hashmap
        unordered_map<int, int> shortestPath;
        
        // minHeap 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});

        while(!minHeap.empty()){
            auto [currWeight, currNode] = minHeap.top(); minHeap.pop();

            if (shortestPath.contains(currNode)){
                continue;
            }

            shortestPath[currNode] = currWeight;

            for(const auto [node, weight] : adjList[currNode]){
                if (shortestPath.contains(node)){
                    continue;
                }

                minHeap.push({currWeight + weight, node});
            }
        }

        vector<long long> result(n, -1);

        for (const auto& [node, distance] : shortestPath){
            result[node] = distance;
        }

        return result;
    }
};

void printResult(vector<long long>& result){
    for (const long long& num : result){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    int n = 5;

    vector<vector<int>> edges = {
    {0, 1, 4},
    {0, 2, 1},
    {2, 1, 2},
    {1, 3, 1},
    {2, 3, 5},
    {3, 4, 3}
    };

    int src = 0;

    vector<long long> result = sol.dijkstra(edges, src, n); // 0 3 1 4 7

    printResult(result);
}