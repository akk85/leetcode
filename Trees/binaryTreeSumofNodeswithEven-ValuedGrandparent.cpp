#include "../common.hpp"

/*
Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. 
If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.

Thought process:
    for each node track its parent and grandparent
    starting at root parent is null and grandparent is null
    for child parent will be this node and its grandparent will be parent of node

    hardware perspective:
    memory is low here since for each tuple we store 3 pointer for node, parent and grandParent
    in a typical 64bit arch that's 3 * 8 = 24bytes per tuple with 10^4 thats 24 * 10000 = 240KB

    we could improve memory effiency by storing int values for the parent and grandParent instead of full raw pointers
    each tuple will now store (8B + 4 + 4) = 16B 
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int depthSum = 0;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++){
                auto node = q.front(); q.pop();

                sum += node->val;
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            depthSum = sum;
        }
        return depthSum;
    }
};