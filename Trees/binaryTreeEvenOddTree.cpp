#include "../common.hpp"

/*
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

Thought process:
    bfs -> get each level
    for each level have a flag is even check all nodes are in descneidng order 
                            if odd level check all nodes are sricly increasing 
        even -> nodes must be odd and increasing
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

using vec = vector<int>;
class Solution {
private:
    bool levelisValid(bool isEven, vec& level){
        for (int node = 0; node < level.size(); node ++){
            if (isEven){
                if (level[node] % 2 == 0 || (node > 0 && level[node] <= level[node - 1])) return false;
            }
            else {
                if (level[node] % 2 != 0 || (node > 0 && level[node] >= level[node - 1])) return false;
            }
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool isEven = true;
        while(!q.empty()){
            int size = q.size();
            vec level;
            for (int i = 0; i < size; i++){
                auto node = q.front(); q.pop();
                level.push_back(node->val);

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            bool satisfied = levelisValid(isEven, level);
            if (!satisfied) return false;
            isEven = !isEven;
        }
        return true;
    }
};