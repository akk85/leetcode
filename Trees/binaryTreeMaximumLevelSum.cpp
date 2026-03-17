#include "../common.hpp"

/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

Thought process:
    do level bfs and update maxLevel and maxSum when we encounter a level sum greater than our currentSum
    due to bfs lowest level with maxSum will be returned if a deeper level with same maxSum is found as we never update a level is sum is same 
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
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int maxSum   = INT_MIN;
        int maxLevel = 0;
        int level    = 0;
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

            if (sum > maxSum){
                maxLevel = level;
                maxSum = sum; 
            }
        }

        return maxLevel;
    }
};