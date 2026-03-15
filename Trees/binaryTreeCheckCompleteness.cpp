#include "../common.hpp"

/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, 
is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.
*/
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

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        
        bool foundNullNode = false;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            if (node == nullptr) foundNullNode = true;

            else if (node != nullptr && foundNullNode == true){
                return false;
            }
            else {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};