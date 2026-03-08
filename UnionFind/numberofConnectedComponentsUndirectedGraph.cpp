#include "../common.hpp"

class Solution {
private:
    vector<int> parent;
    vector<int> size;
    int FindRoot(int node){
        int root = parent[node];
        while(root != parent[root]){
            root = parent[root];
        }
        return root;
    }
    void Union(int node1, int node2){
        int root1 = FindRoot(node1), root2 = FindRoot(node2);

        if (root1 == root2){
            return;
        }
        else if (size[root1] >= size[root2]){
            parent[root2] = root1;
            size[root1] += size[root2];
        }
        else {
            parent[root1] = root2;
            size[root2] += size[root1];       
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n);

        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node] = 1;
        }

        for (const vector<int>& edge : edges){
            int node1 = edge[0], node2 = edge[1];
            Union(node1, node2);
        }

        unordered_set<int> roots;

        for (int node = 0; node < n; node ++){
            int root = FindRoot(node);
            roots.insert(root);
        }

        return roots.size();
    }
};

int main(){
    Solution sol;

    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {3,4}
    };

    cout << sol.countComponents(5, edges) << endl; // 2

    edges = {
        {0,1},
        {1,2},
        {2,3},
        {3,4}
    };

    cout << sol.countComponents(5, edges) << endl; // 1
}