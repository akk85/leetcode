#include "../common.hpp"

/*
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

Thought process:
    Find deepest leaf nodes
    Use a stack pop two nodes and find lca and push back lca until stack is of size 1
    return remaining node
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
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

        return stk.top();
    }
};