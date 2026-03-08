#include "../common.hpp"

/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

Thought process:
    Use union find to find number of connected components
    if edges - 1 < nodes return -1 impossible for a connection
    return valid connections - 1 
*/

class Solution {
private:
    vector<int> parent;
    vector<int> size;
    int FindRoot(int node){
        while(node != parent[node]){
            node = parent[node];
        }
        return node;
    }
    void Union(int node1, int node2){
        int root1 = FindRoot(node1);
        int root2 = FindRoot(node2);

        if (root1 == root2){
            return;
        }
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1] += size[root2];
        }
        else {
            parent[root1] = root2;+
            size[root2] += size[root1];
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        size.resize(n);
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node] = 1;
        }

        for (const vector<int>& edge : connections){
            int node1 = edge[0], node2 = edge[1];
            Union(node1, node2);
        }

        unordered_set<int> roots;
        for (int node = 0; node < n; node ++){
            roots.insert(FindRoot(node));
        }

        int edges = connections.size();
        if (edges < n - 1){
            return -1;
        }

        return roots.size() - 1;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {1,2}
    };

    cout << sol.makeConnected(4, edges) << endl; // 1

    edges = {
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {1,3}
    };

    cout << sol.makeConnected(6, edges) << endl; // 2
}