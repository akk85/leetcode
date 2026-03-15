#include "../common.hpp"

/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
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
    unordered_map<TreeNode* , TreeNode*> nodeParentMap;
    unordered_set<TreeNode*> visited;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // step 1 connect tree nodes to parents making it a graph
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if (node->left){
                nodeParentMap[node->left]  = node;
                q.push(node->left);
            }
            if (node->right){
                nodeParentMap[node->right] = node;
                q.push(node->right);
            }
        }

        // step 2: level bfs starting from targetNode
        q.push(target);
        visited.insert(target);
        int level = 0;
        while(!q.empty() && level != k){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if (node->left && !visited.contains(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.contains(node->right)){
                    q.push(node->right);
                    visited.insert(node->left);
                }
                if (nodeParentMap.contains(node) && !visited.contains(nodeParentMap[node])){
                    TreeNode* parent = nodeParentMap[node];
                    q.push(parent);
                    visited.insert(parent);
                }
            }
            level += 1;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};