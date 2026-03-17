#include "../common.hpp"

/*
A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.
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
public:
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front(); q.pop();

            if (node->left){
                if (node->val != node->left->val)  return false;
                q.push(node->left);
            }
            if (node->right){
                if (node->val != node->right->val) return false;
                q.push(node->right);
            }
        }
        return true;
    }
};