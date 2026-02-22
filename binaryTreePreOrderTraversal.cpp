#include "common.hpp"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

/*
You are given the root of a binary tree, return the preorder traversal of its nodes' values.

postorder means root left then right

initialize stack with root
    while stack
        pop top element
        push to result array
        push right child then left child so that left can be visited before right child (LIFO)
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* curr = s.top(); s.pop();
            res.push_back(curr->val);

            if (curr->right) s.push(curr->right);
            if (curr->left)  s.push(curr->left);
        }

        return res;
    }
};

void printResult(const vector<int>& result){
    for (const int& val : result){
        cout << val << " ";
    }
    cout << endl;
}

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1,
    new TreeNode(2, new TreeNode(4), new TreeNode(5)),
    new TreeNode(3, new TreeNode(6), new TreeNode(7)));

    vector<int> result = sol.preorderTraversal(root);

    printResult(result);
}