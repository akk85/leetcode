#include "../common.hpp"

/*
You are given a 2D integer array properties having dimensions n x m and an integer k.

Define a function intersect(a, b) that returns the number of distinct integers common to both arrays a and b.

Construct an undirected graph where each index i corresponds to properties[i]. 

There is an edge between node i and node j if and only if intersect(properties[i], properties[j]) >= k, 
where i and j are in the range [0, n - 1] and i != j.

Return the number of connected components in the resulting graph.

Thiught process:
    for each vector edge in array
        for each other vector in array
            if coomon elements in both vectors is greater than k
                union(node1, node2) // nodes here are the index of the two vectors.

    count components in the dsu 
*/

using vec = vector<int>;
class UnionFind{
private:
    vec parent;
    vec size;
public:
    UnionFind(int n){
        for (int node = 0; node < n; node ++){
            parent.resize(n);
            size.resize(n);
            parent[node] = node;
            size[node]   = 1;
        }
    }
    int Find(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]];
            node = parent[node];
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
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();

        unordered_map<int, unordered_set<int>> setMap;
        for (int node = 0; node < n; node ++){
            vec edge = properties[node];
            unordered_set<int> edgeSet(edge.begin(), edge.end());
            setMap[node] = edgeSet;
        }

        UnionFind unionFind(n);
        for (int i = 0; i < n; i ++){
            for (int j = i + 1; j < n; j ++){
                vec edge1 = properties[i], edge2 = properties[j];
                
                unordered_set<int> set1 = setMap[i];
                unordered_set<int> set2 = setMap[j];

                int common = 0;
                for (const int& val : set1){
                    if (set2.contains(val)){
                        common += 1;
                    }
                }

                if (common >= k){
                    unionFind.Union(i, j);
                } 
            }
        }

        // find components
        unordered_set<int> roots;
        for (int node = 0; node < n; node ++){
            int root = unionFind.Find(node);
            roots.insert(root);
        }

        return roots.size();
    }
};

int main(){
    Solution sol;

    int k = 1;
    vector<vector<int>> properties = {{1,2},{1,1},{3,4},{4,5},{5,6},{7,7}};

    cout << sol.numberOfComponents(properties, k) << endl; // 3

    k = 2;
    properties = {{1,2,3},{2,3,4},{4,3,5}};

    cout << sol.numberOfComponents(properties, k) << endl; // 1
}