#include "../common.hpp"

/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.
*/

using vec = vector<int>;
class Solution {
private:
    vec parent;
    vec size;
    int Find(int node){
        while(node != parent[node]){
            parent[node] = parent[parent[node]]; // path comprehension
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
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1){
            return false;
        }
        // self node parents 
        parent.resize(n);
        size.resize(n);
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }
        // union whole graph
        for (const vec& edge : edges){
            int node1 = edge[0], node2 = edge[1];
            bool alreadyConnected = Union(node1, node2);
            if (alreadyConnected){
                return false;
            }
        }

        int numberofNodes = size[Find(0)];

        if (numberofNodes != n){
            return false;
        }

        return true;
    }
};

int main(){
    Solution sol;

    int n = 5;  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};

    cout << boolalpha << sol.validTree(n, edges) << endl;   // true

    n = 5; edges = {{0, 1}, {0, 2}, {2, 3}, {1, 3}, {1, 4}};

    cout << boolalpha << sol.validTree(n, edges) << endl;    // false 
 
    n=6;  edges = {{0, 1}, {2, 3}, {4, 5}, {3, 4}, {2, 5}};  // false 

    cout << boolalpha << sol.validTree(n, edges) << endl;
}
