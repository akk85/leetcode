#include "../common.hpp"

/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 

The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge
between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*/

using vec = vector<int>;
class Solution {
private:
    vec parent;
    vec size;
    int Find(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]]; // path compression
            node = parent[node];
        }
        return node;
    }
    bool Union(int node1, int node2){
        int root1 = Find(node1), root2 = Find(node2);

        if (root1 == root2){
            return true; // already connected
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        size.resize(n);
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }

        // make union connections
        for (const vec& edge : edges){
            Union(edge[0], edge[1]);
        }

        // check if source and destination in same components
        int sourceRoot      = Find(source);
        int destinationRoot = Find(destination);

        return sourceRoot == destinationRoot;
    }
};


int main(){
    Solution sol;

    int n = 3, source = 0, destination = 2;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}};

    cout << boolalpha << sol.validPath(n, edges, source, destination) << endl; // true;

    n = 6, source = 0, destination = 5;
    edges = {{0,1}, {0,2}, {3,5}, {5,4}, {4,3}};

    cout << boolalpha << sol.validPath(n, edges, source, destination) << endl; // false;


}
