#include "../common.hpp"    

/*
Given a Binary tree, the task is to find the distance between two keys in a binary tree, no parent pointers are given. 

The distance between two nodes is the minimum number of edges to be traversed to reach one node from another. 

The given two nodes are guaranteed to be in the binary tree and all node values are unique.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* findLCA(TreeNode* root, int node1, int node2){
        unordered_map<TreeNode*, TreeNode*> nodeParentMap;
        nodeParentMap[root] = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* node1Pointer; TreeNode* node2Pointer;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if (node->val == node1) node1Pointer = node;
            if (node->val == node2) node2Pointer = node;

            if (node->left) {
                nodeParentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right){
                nodeParentMap[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> node1Parents;
        TreeNode* node = node1Pointer;

        while(node){
            node1Parents.insert(node);
            node = nodeParentMap[node];
        }

        node = node2Pointer;
        while(node){
            if (node1Parents.contains(node)){
                return node;
            }
            node = nodeParentMap[node];
        }

        return nullptr; // never get here as LCA is guarenteed;
    }

    int findSteps(TreeNode* LCA, int candidate){
        stack<pair<TreeNode*, int>> s; // node -> steps
        s.push({LCA, 0});

        while(!s.empty()){
            auto [node, steps] = s.top(); s.pop();
            if (node->val == candidate) return steps;

            if (node->left)  s.push({node->left,  steps + 1});
            if (node->right) s.push({node->right, steps + 1});
        }

        return 0;
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* LCA = findLCA(root, p, q);

        int steps1 = findSteps(LCA, p);
        int steps2 = findSteps(LCA, q);

        int steps = steps1 + steps2;
        return steps;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Test 1: " << sol.findDistance(root, 4, 5) << endl;  // 2
    cout << "Test 2: " << sol.findDistance(root, 4, 3) << endl;  // 3
    cout << "Test 3: " << sol.findDistance(root, 2, 3) << endl;  // 2
    cout << "Test 4: " << sol.findDistance(root, 2, 4) << endl;  // 2
    cout << "Test 5: " << sol.findDistance(root, 1, 1) << endl;  // 0

    return 0;
}