#include "../common.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};
/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. 
You are also given an integer startValue representing the value of the start node s, and a different integer destValue 
representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of 
such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. 
Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.
*/


/**
Thought process:
    find lca
    find path from lca to node1 and reverse path to all U's
    find path from lca to node2
    combine path1 and path2 together
*/

class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> nodeParentMap;
    TreeNode* findLCA (TreeNode* root, int startValue, int destValue){
        queue<TreeNode*> q;
        nodeParentMap[root] = nullptr;
        q.push(root);

        TreeNode* node1;
        TreeNode* node2;
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if (node->val == startValue) node1 = node;
            else if (node->val == destValue)  node2 = node;

            if (node->left){
                nodeParentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right){
                nodeParentMap[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> startNodeParents;

        while(node1){
            startNodeParents.insert(node1);
            node1 = nodeParentMap[node1];
        }

        while(node2){
            if (startNodeParents.contains(node2)){
                return node2;
            }
            node2 = nodeParentMap[node2];
        }

        return nullptr;
    }

    int LCAtoStartNodeSteps(TreeNode* lca, int start){
        queue<pair<TreeNode*, int>> q; // node , steps 
        q.push({lca, 0});

        while(!q.empty()){
            auto [node, steps] = q.front(); q.pop();

            if (node->val == start){
                return steps;
            }

            if (node->left){
                q.push({node->left, steps + 1});
            }
            if (node->right){
                q.push({node->right, steps + 1});
            }
        }
        return 0; // we never get here
    }

    bool dfs(TreeNode* node, int end, string& path){
        if (node->val == end) return true;
        if (node->left){
            path += 'L';
            if (dfs(node->left, end, path)) return true;
            path.pop_back();
        }
        if (node->right){
            path += 'R';
            if (dfs(node->right, end, path)) return true;
            path.pop_back();
        }
        return false;
    }

    string LCAtoEndNode(TreeNode* lca, int end){
        string path = "";
        dfs(lca, end, path);
        return path;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);

        int steps = LCAtoStartNodeSteps(lca, startValue);

        string path1;
        for (int i = 0; i < steps; i++){
            path1 += 'U';
        }

        string path2;
        path2 = LCAtoEndNode(lca, destValue);


        string fullPath = path1 + path2;

        return fullPath;

    }
};