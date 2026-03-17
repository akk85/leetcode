#include "../common.hpp"

/*
Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> nodeParentMap;
    bool nodeIsLeaf(TreeNode* node){
        return (!node->left && !node->right);
    }
    TreeNode* findLCA(TreeNode* node1, TreeNode* node2){
        
        unordered_set<TreeNode*> node1Parents;
        while(node1){
            node1Parents.insert(node1);
            node1 = nodeParentMap[node1];
        }

        while(node2){
            if (node1Parents.contains(node2)){
                return node2;
            }
            node2 = nodeParentMap[node2];
        }
        return nullptr;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        nodeParentMap[root] = nullptr;

        q.push({root, 1});
        int maxDepth = 0; vector<TreeNode*> deepestLeaves;
        while(!q.empty()){
            auto [node , depth] = q.front(); q.pop();

            if (nodeIsLeaf(node)){
                if (depth > maxDepth){
                    deepestLeaves.clear();
                    deepestLeaves.push_back(node);
                    maxDepth = depth;
                } else if (depth == maxDepth){
                    deepestLeaves.push_back(node);
                }
            }

            if (node->left){
                nodeParentMap[node->left] = node;
                q.push({node->left,  depth + 1});
            }
            if (node->right){
                nodeParentMap[node->right] = node;
                q.push({node->right, depth + 1});
            }
        }

        stack<TreeNode*> stk;
        for (const auto& leaf : deepestLeaves){
            stk.push(leaf);
        }

        while(stk.size() > 1){
            TreeNode* node1 = stk.top(); stk.pop();
            TreeNode* node2 = stk.top(); stk.pop();

            TreeNode* LCA = findLCA(node1, node2);
            stk.push(LCA);
        }

        root = stk.top(); stk.pop();
        return root;
    }
};