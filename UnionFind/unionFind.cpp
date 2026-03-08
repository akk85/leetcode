#include "../common.hpp"

class UnionFind{
private:
    vector<int> parent; // index = node -> parent
    vector<int> size;   // idnex = node -> size
    int Find(int node){
        int root = node;

        while(root != parent[root]){
            root = parent[root];
        }

        return root;
    }

    void Union(int node1, int node2){
        int root1 = Find(node1);
        int root2 = Find(node2);

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
};
