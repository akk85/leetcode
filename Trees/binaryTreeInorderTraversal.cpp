#include "../common.hpp"

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
You are given the root of a binary tree, return the inorder traversal of its nodes' values.

inorder traversal means left root right
Intuition:
    go all the way left process left process root if root has right process it process it 


pseudo code 
    use a stack
    curr = root
    while curr or stack not empty 
        // go as left as possible 
        while curr
            stack.push(curr)
            curr = curr.left

        // now curr is nullptr we start popping 
        curr = stack.top(); stack.pop()

        result.push(curr);
        curr = curr.right;

*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        TreeNode* curr = root;
        stack<TreeNode*> stk;

        while (curr || !stk.empty()){
            // go left
            while (curr){
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top(); stk.pop();
            res.push_back(curr->val);
            curr = curr->right;
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

    vector<int> result = sol.inorderTraversal(root);

    printResult(result);
}