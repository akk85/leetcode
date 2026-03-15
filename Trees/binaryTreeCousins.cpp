#include "../common.hpp"

/*
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, 
return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, 
and children of each depth k node are at the depth k + 1.


q 
1
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
private:
    unordered_map<int, pair<int, int>> parentHeightMap; // node -> (parent, height)
public:
    bool isCousins(TreeNode* root, int x, int y) {
        parentHeightMap[root->val] = {-1, 0};

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto [node, depth] = q.front(); q.pop();

            if (node->left){
                parentHeightMap[node->left->val] = {node->val, depth};
                q.push({node->left, depth + 1});
            }

            if (node->right){
                parentHeightMap[node->right->val] = {node->val, depth};
                q.push({node->right, depth + 1});
            }
        }

        auto [parent1, height1] = parentHeightMap[x];
        auto [parent2, height2] = parentHeightMap[y];

        return (height1 == height2 && parent1 != parent2);
    }
};

