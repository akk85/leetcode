#include "../common.hpp"
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


/*
Given the root of a binary tree, return the leftmost value in the last row of the tree.

Thought process:
    left most node bottom node just means the left most node in the last level
    I could iterate over the tree via bfs and keep updating my global left node with the lett mnode
    in each levekl. After last level variable will have bottom left node

    time O(n) and space is O(n) worst case when all nodes are in one level 
psudeo code
    queueu push root
    while queue
        size = qsize
        for (int i = 0; i < n; i++)
            node = q.pop
            if i == 0
                bottomleft = node
            if leftnode push leftbode
            if rightnode push rightnode
    
    return bottomleft
*/


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int bottomLeftNode = root->val;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if (i == 0) bottomLeftNode = node->val;
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return bottomLeftNode;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    cout << sol.findBottomLeftValue(root) << endl;
    delete root;

    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, new TreeNode(5, new TreeNode(7), nullptr), new TreeNode(6)));

    cout << sol.findBottomLeftValue(root) << endl;
    delete root;

}