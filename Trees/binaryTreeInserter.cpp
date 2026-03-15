#include "../common.hpp"

/*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the CBTInserter class:

CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
TreeNode get_root() Returns the root node of the tree.
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
class CBTInserter {
private:
    TreeNode* treeRoot;
    queue<TreeNode*> q; // nodes with room for children
public:
    CBTInserter(TreeNode* root) {
        treeRoot = root;

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while(!bfsQueue.empty()){
            TreeNode* node = bfsQueue.front(); bfsQueue.pop();

            if (node->left == nullptr || node->right == nullptr){
                q.push(node);
            }

            if (node->left)  bfsQueue.push(node->left);
            if (node->right) bfsQueue.push(node->right);
        }
    }
    
    int insert(int val) {
        TreeNode* node  = q.front();
        TreeNode* child = new TreeNode(val);

        if (node->left == nullptr){
            node->left = child;
        } else {
            node->right = child;
        }

        if (node->left && node->right){
            q.pop();
        }

        q.push(child);

        return node->val;
    }
    
    TreeNode* get_root() {
        return treeRoot;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    CBTInserter cBTInserter(root);

    cout << cBTInserter.insert(3) << endl;  // 1

    cout << cBTInserter.insert(4) << endl;  // 2

    return 0;
}