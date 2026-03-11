#include "../common.hpp"

/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

Intuition:
    Union each node with its left and right child
    if either node already exist in graph return false;

    keep track of each nodes parent count
    parent vec / map should have all nodes have exactly 1 parent and have exactly one node with zero parent(root node)
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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        size.resize(n);
        // self parent each node
        for (int node = 0; node < n; node ++){
            parent[node] = node;
            size[node]   = 1;
        }

        vec parentCount(n);
        for (int node = 0; node < n; node ++){
            int leftnode  = leftChild[node];
            int rightnode = rightChild[node];

            if (leftnode == -1 && rightnode == -1){
                continue;
            }

            if (leftnode != -1){
                parentCount[leftnode] += 1;
                bool alreadyConnected = Union(node, leftnode);
                if (alreadyConnected){
                    return false;
                }
            }
            if (rightnode != -1){
                parentCount[rightnode] += 1;
                bool alreadyConnected = Union(node, rightnode);
                if (alreadyConnected){
                    return false;
                }
            }
        }

        // validate only one component in DSU
        unordered_set<int> roots;
        for (int node = 0; node < n; node ++){
            int root = Find(node);
            roots.insert(root);
        }

        if (roots.size() != 1){
            return false;
        }

        // validate parent count and number of roots
        int rootCount = 0;
        for (int node = 0; node < n; node ++){
            if (parentCount[node] == 0){
                rootCount += 1;
            }
            if (parentCount[node] > 1){
                return false;
            }
        }

        return rootCount == 1;
    }
};

int main(){
    Solution sol;

    int n = 4;
    vector<int> leftChild  = {1,-1,3,-1};
    vector<int> rightChild = {2,-1,-1,-1};

    cout << boolalpha << sol.validateBinaryTreeNodes(n, leftChild, rightChild) << endl; // true

    n = 4;
    leftChild  = {1,-1,3,-1};
    rightChild = {2,3,-1,-1};

    cout << boolalpha << sol.validateBinaryTreeNodes(n, leftChild, rightChild) << endl; // false;

    n = 2;
    leftChild  = {1,0};
    rightChild = {-1,-1};

    cout << boolalpha << sol.validateBinaryTreeNodes(n, leftChild, rightChild) << endl; // false;
}