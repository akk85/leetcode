#include "../common.hpp"

/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
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

using vec = vector<int>;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vec ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int maxNode = INT_MIN;
            for (int i= 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                maxNode = max(maxNode, node->val);
                
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(maxNode);
        }

        return ans;
    }
};