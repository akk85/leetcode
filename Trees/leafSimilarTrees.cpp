#include "../common.hpp"

/*
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
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

using vec = vector<int>;
class Solution {
private:
    vec inOrder(TreeNode* root){
        vec result;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while(curr || !s.empty()){
            // push left
            while(curr){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop();
            if (!curr->left && !curr->right){
                result.push_back(curr->val);
            }
            curr = curr->right;
        }
        return result;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            return inOrder(root1) == inOrder(root2);
    }
};

// 3 5 6 