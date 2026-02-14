#include "common.hpp"


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
    void levelOrder(TreeNode* root){
        if (!root) return;

        queue<TreeNode* > q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                cout << node->val << " ";
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            cout << endl;
        }
    }
};


int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1,new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));

    sol.levelOrder(root);

    delete root;
}