#include "../common.hpp"

/*
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

Thought process:
    first bfs to map each level with sum
    2nd bfs run to update node with level path - sum of siblings
    we can update children from their parents
    so for each child, its repalcement is level sum - sibling sum
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
private:
    unordered_map<int, int> sumLevelMap;
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // find level Sum   
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            int sum = 0;

            for (int i = 0; i < size; i++){
                auto node = q.front(); q.pop();
                sum += node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level += 1;
            sumLevelMap[level] = sum;
        }

        // update nodes
        root->val = 0;
        queue<pair<TreeNode*, int>> bfsQueue;
        bfsQueue.push({root, 1});
        while(!bfsQueue.empty()){
            auto [node, depth] = bfsQueue.front(); bfsQueue.pop();

            int levelSum = sumLevelMap[depth + 1];
            if (node->left && node->right){
                int siblingSum = node->left->val + node->right->val;
                node->left->val  = levelSum - siblingSum;
                node->right->val = levelSum - siblingSum;
                bfsQueue.push({node->left,  depth + 1});
                bfsQueue.push({node->right, depth + 1});
            }
            else if (node->left){
                int siblingSum = node->left->val;
                node->left->val  = levelSum - siblingSum;
                bfsQueue.push({node->left, depth + 1});
            }
            else if (node->right){
                int siblingSum = node->right->val;
                node->right->val = levelSum - siblingSum;
                bfsQueue.push({node->right, depth + 1});
            }
            
        }

        return root;
    }
};