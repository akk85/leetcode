#include "common.hpp"

/*
You are given a connected undirected graph with n nodes labeled from 1 to n. 

Initially, it contained no cycles and consisted of n-1 edges.

We have now added one additional edge to the graph. 

The edge has two different vertices chosen from 1 to n, and was not an edge that previously existed in the graph.

The graph is represented as an array edges of length n where edges[i] = [ai, bi] represents an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the graph is still a connected non-cyclical graph. 

If there are multiple answers, return the edge that appears last in the input edges.

[1,2],[1,3],[1,4],[3,4],[4,5]]


1 > 2 3 4
2 > 1
3 > 1 4
4 > 1 3 5
5 > 4

visited = 1 2 3 4 5
queue   = 

curr = 5

nei = 1 3 5

res = 3 4

parent node
1 2
1 3
1 4
3 4
4 5

*/

class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        
        for (int i = 1; i <= n; i++ ){
            parent[i] = i;
            rank[i]   = 1;
        }

        for (const vector<int>& edge : edges){
            int node1 = edge[0];
            int node2 = edge[1];
            bool connected = unionFind(node1, node2);
            if (connected){
                return edge;
            }
        }
        return {};

    }
    bool unionFind(int node1, int node2){
        int node1Parent = findParent(node1);
        int node2Parent = findParent(node2);

        if (node1Parent == node2Parent){
            return true; // cycle detected
        }

        if (rank[node1Parent] > rank[node2Parent]){
            parent[node2Parent] = node1Parent;
            rank[node1Parent]  += rank[node2Parent];
        } else {
            parent[node1Parent] = node2Parent;
            rank[node2Parent]  += rank[node1Parent];
        }
        return false;
    }

    int findParent(int node){
        int nodeParent = parent[node];

        while(nodeParent != parent[nodeParent]){
            nodeParent = parent[nodeParent];
        }
        return nodeParent;
    }

};

void printResult(vector<int>& result){
    for (const int& num : result){
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    vector<vector<int>> edges = {{1,2}, {1,3}, {3,4}, {2,4}};

    vector<int> result = sol.findRedundantConnection(edges); // 2,4

    printResult(result);
}


/*

Minimum Time to Visit a Cell In a Grid
*/