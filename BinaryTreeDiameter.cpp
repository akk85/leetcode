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

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        unordered_map<TreeNode*, int> height;
        stack<pair<TreeNode*, bool>> stack;

        int maxDiameter = 0;
        stack.push({root, false});
        while(!stack.empty()){
            auto [node, visited] = stack.top(); stack.pop();

            if (!node) continue;
            
            if (visited){
                int leftHeight, rightHeight;

                if (node->left)  leftHeight = height[node->left];
                else leftHeight  = -1;

                if (node->right) rightHeight = height[node->right];
                else rightHeight = -1;

                height[node] = 1 + max(leftHeight, rightHeight);
                int currDiameter = 1 + leftHeight + 1 + rightHeight;
                maxDiameter = max(maxDiameter, currDiameter);
            }
            else {
                stack.push({node, true});
                stack.push({node->right, false});
                stack.push({node->left,  false});
            }
        }

        return maxDiameter;
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(2);

    TreeNode* left  = new TreeNode(1);
    TreeNode* right = new TreeNode(3);
    root->left = left; root->right = right;

    cout << sol.diameterOfBinaryTree(root) << endl;

    delete root;
}   