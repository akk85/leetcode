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


class Solution{
public:
    int maxDepth(TreeNode* root){
        if (!root){
            return 0;
        }
        int maxDepth {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()){
            auto [node, level] = q.front(); q.pop();
            maxDepth = max(maxDepth, level);

            if (node->left){
                q.push({node->left, level + 1});
            }
            if (node->right){
                q.push({node->right, level + 1});
            }
        }
        return maxDepth;
    }
};


int main(){
    Solution sol;
    TreeNode* root = 
        new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4), new TreeNode(5)));

    cout << sol.maxDepth(root) << endl; // 3

    delete root;
}