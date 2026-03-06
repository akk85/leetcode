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
Thought process:
    1. Do an inorder traversal of bst and store in vector
    2. result vector if is a valid bst should be sorted
    3. traverse the vector checking if all values are in an increasing manner return false if not otherwise true
 */
class Solution {
public:
    bool isValidBSTVector(TreeNode* root) {
        vector<int> res;

        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr || !s.empty()){
            while (curr){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        int n = res.size();
        for (int i = 1; i < n; i++){
            if (res.at(i - 1) >= res.at(i)){
                return false;
            }
        }
        return true;
    }

    bool isValidBSTOptimal(TreeNode* root) {

        stack<TreeNode*> s;
        TreeNode* curr = root;
        int prev = INT_MIN;
        while (curr || !s.empty()){
            while (curr){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop();
            if (curr->val <= prev) return false;
            prev = curr->val;
            curr = curr->right;
        }

        return true;
    }
};

int main(){
    Solution sol;

    // example 1
    TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    cout << boolalpha << sol.isValidBSTVector(root1) << endl;

    delete root1;

    TreeNode* root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    cout << boolalpha << sol.isValidBSTVector(root2) << endl;

    delete root2;

    // example 2
    TreeNode* root3 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << boolalpha << sol.isValidBSTVector(root3) << endl;

    delete root3;

    TreeNode* root4 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << boolalpha << sol.isValidBSTVector(root4) << endl;

    delete root4;

}