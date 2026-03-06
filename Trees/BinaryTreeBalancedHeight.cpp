#include "../common.hpp"

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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        unordered_map<TreeNode*, int> height;
        stack<pair<TreeNode*, bool>> stack;

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

                if (abs(leftHeight - rightHeight) > 1) return false;

                height[node] = 1 + max(leftHeight , rightHeight);
            }
            else {
                stack.push({node, true});
                stack.push({node->right, false});
                stack.push({node->left,  false});
            }
        }

        return true;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4, new TreeNode(5), nullptr), nullptr));

    cout << boolalpha << sol.isBalanced(root) << endl;

    delete root;
}