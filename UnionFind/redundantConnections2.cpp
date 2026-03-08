#include "../common.hpp"

/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) 
for which all other nodes are descendants of this node, 
plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), 
with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not 
an edge that already existed.

The resulting graph is given as a 2D-array of edges. 
Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, 
where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array.

Three cases:
    Two parents with a cycle
    Two parents no cycle
    Just a cycle

*/

using vec = vector<int>;
class Solution {
private:
    vec parent;
    vec size;
    int Find(int node){
        while(node != parent[node]){
            node = parent[node];
        }
        return node;
    }
    bool Union(int parentNode, int childNode){
        int root1 = Find(parentNode);
        int root2 = Find(childNode);

        if (root1 == root2){ // already in graph return true
            return true;
        }
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1]  += size[root2];
        }
        else{
            parent[root1] = root2;
            size[root2]  += size[root1];
        }
        return false;
    }
public:
    vec findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int node = 1; node <= n; node ++){
            parent[node] = -1;    // mark nodes with no parent yet  
        }

        bool hasTwoParent = false;
        vec candidate1;
        vec candidate2;

        // find if any node has two parents ->invalidates tree
        for (const vec& edge : edges){
            int par = edge[0], child = edge[1];
            if (parent[child] != -1){
                candidate1 = {parent[child], child};
                candidate2 = {par, child};
                hasTwoParent = true;
            }
            else {
                parent[child] = par;
            }
        }

        // build union parent self mapping
        for (int node = 1; node <= n; node ++){
            parent[node] = node;   
            size[node]   = 1; 
        }

        // do the union find for each edge 
        for (const vec& edge : edges){
            if (edge == candidate2){
                continue;
            }

            int par = edge[0], child = edge[1];
            bool hasCycle = Union(par, child);

            if (hasCycle && hasTwoParent){
                return candidate1;
            }
            else if(hasCycle){
                return edge;
            }
        }
        return {};  //never get here
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

    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};

    vector<int> result = sol.findRedundantDirectedConnection(edges); // 2,3

    printResult(result);

    edges = {{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};

    result = sol.findRedundantDirectedConnection(edges); // 4, 1

    printResult(result);
}