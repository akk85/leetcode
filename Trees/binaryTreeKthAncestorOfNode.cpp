#include "../common.hpp"

/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where 
parent[i] is the parent of ith node. 

The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.

int getKthAncestor(int node, int k) return the kth ancestor of the given node node. 
If there is no such ancestor, return -1.

0 = -1
1 = 0
2 = 0
3 = 1
4 = 1
5 = 2
6 = 2

6 3
node = 0
steps 2

*/

class TreeAncestor {
private:
    unordered_map<int, int> nodeParentMap;
public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < n; i ++){
            int node   = i;
            int par    = parent[node];
            nodeParentMap[node] = par;
        }
    }
    
    int getKthAncestor(int node, int k) {

        int steps = 0;
        while(node != -1 && steps < k){
            node = nodeParentMap[node];
            steps ++;
        }
        
        return node;
    }
};