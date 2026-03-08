#include "../common.hpp"

/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 

The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge 
between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the input.

Thought Process:
    Union all edges using union find and if roots of nodes in an edge are same 
    it means we have already connected this nodes before and can just return it
*/

class Solution {
private:
    vector<int> parent;
    vector<int> size;

    int Find(int node){
        while(node != parent[node]){
            node = parent[node];
        }
        return node;
    }
    bool Union(int node1, int node2){
        int root1 = Find(node1);
        int root2 = Find(node2);

        if (root1 == root2){   // already in graph return true
            return true;
        }
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1]  += size[root2];
        }
        else {
            parent[root1] = root2;
            size[root2]  += size[root1];
        }

        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int node = 1; node <= n; node ++){
            parent[node] = node;
            size[node] = 1;
        }

        for (const vector<int>& edge : edges){
            int node1 = edge[0], node2 = edge[1];

            bool alreadyConnected = Union(node1, node2);

            if (alreadyConnected){
                return edge;
            }
        }

        return {}; // never gets here 
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

    edges = {{1,2}, {1,3}, {3,4}, {1,4}, {1,5}};

    result = sol.findRedundantConnection(edges); // 1, 4

    printResult(result);
}