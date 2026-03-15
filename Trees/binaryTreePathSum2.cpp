#include "../common.hpp"

/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths 
where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Thought process:
    track each node with its path and pathsum append path if node == leafnode && pathSum == targetSum
    dfs or bfs same complexity 
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
    bool isLeafNode(TreeNode* node){
        if (!node->left && !node->right){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        stack<tuple<TreeNode*, vector<int>, int>> s; // node, path, sum

        vector<int> currPath = {root->val};
        s.push({root, currPath, root->val});

        vector<vector<int>> res;
        while(!s.empty()){
            auto [node, path, sum] = s.top(); s.pop();

            if (isLeafNode(node) && sum == targetSum) {
                res.push_back(path);
            }

            if (node->left){
                vector<int> newPath = path;
                newPath.push_back(node->left->val);
                int newSum          = sum + node->left->val;
                s.push({node->left, newPath, newSum});
            }
            if (node->right){
                vector<int> newPath = path;
                newPath.push_back(node->right->val);
                int newSum          = sum + node->right->val;
                s.push({node->right, newPath, newSum});
            }
        }

        return res;
    }
};