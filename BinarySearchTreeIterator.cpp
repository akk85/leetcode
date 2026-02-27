#include "common.hpp"

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

class BSTIterator {
private:
    stack<TreeNode*> stk;
    void pushLeft(TreeNode* node){
        while(node){
            stk.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curr = stk.top(); stk.pop();

        if (curr->right){
            pushLeft(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};
