#include "../common.hpp"

/*
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 Thoought process:
    bfs for each level updating depthsum with each level sum
    at the end depthSum will be holding sum of last level
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