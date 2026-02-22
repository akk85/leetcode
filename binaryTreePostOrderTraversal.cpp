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
You are given the root of a binary tree, return the postorder traversal of its nodes' values.

Thought process:
    1. Need a way to get a roots children before we get the root itself
    2. we can use two stack
    3. stack 1 for traversal and stack 2 for postorder
    we pop a node from stack1 and push it to stack2 and then for its children we push them into stack1 and continue

*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> stk1, stk2;

        stk1.push(root);

        while(!stk1.empty()){
            TreeNode* curr = stk1.top(); stk1.pop(); 
            stk2.push(curr);

            if (curr->left)  stk1.push(curr->left);
            if (curr->right) stk1.push(curr->right);
        }

        while(!stk2.empty()){
            TreeNode* curr = stk2.top(); stk2.pop();
            res.push_back(curr->val);
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

    vector<int> result = sol.postorderTraversal(root);

    printResult(result);
}