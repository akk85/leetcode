#include "../common.hpp"

/*
You are given an integer n. 
There is an undirected graph with n nodes, numbered from 0 to n - 1. 
You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Thought process:
    number of unreachable nodes for each node is just total nodes - nodes in its components
    we can for each node find its unreachable nodes and add that to tally and return tally / 2 since each node will get double counted
    
    optimize;
    using each components size unreachble nodes per component is just nodes in component * size of other components 
    for component i in components
        for component j in components
            unreachble nodes = size of i * size of j
            total += unreachble nodes

    return unreachble nodes 
*/

using vec = vector<int>;
class UnionFind{
public:
    vec parent;
    vec size;
    UnionFind(int n){
        parent.resize(n);
        size.resize(n);
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }
    }
    int Find(int node){
        while (node != parent[node]){
            parent[node] = parent[parent[node]];
            node         = parent[node];
        }
        return node;
    }

    void Union(int node1, int node2){
        int root1 = Find(node1), root2 = Find(node2);

        if (root1 == root2){
            return;
        }
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1]  += size[root2];
        }
        else {
            parent[root1] = root2;
            size[root2]  += size[root1];
        }
    } 
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind unionFind(n);
        for (const vec& edge : edges){
            int node1 = edge[0], node2 = edge[1];
            unionFind.Union(node1, node2);
        }

        vec compSizes;
        for (int node = 0; node < n; node ++){
            int nodeParent = unionFind.Find(node);

            if (node != nodeParent){    // not root for component  
                continue;
            }

            int componentSize = unionFind.size[node];
            compSizes.push_back(componentSize);
        }

        int components = compSizes.size();
        long long totalPairs = 0;
        for (int i = 0; i < components; i++){
            for (int j = i + 1; j < components; j++){
                long long unreachablePairs = compSizes[i] * compSizes[j];
                totalPairs += unreachablePairs;
            }
        }

        return totalPairs;
    }
};

int main(){
    Solution sol;

    int n = 3;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2}};

    cout << sol.countPairs(n, edges) << endl; // 0

    n = 7;
    edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};

    cout << sol.countPairs(n, edges) << endl; // 14
}