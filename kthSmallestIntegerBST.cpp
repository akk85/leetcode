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

/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.

A binary search tree satisfies the following constraints:

The left subtree of every node contains only nodes with keys less than the node's key.
The right subtree of every node contains only nodes with keys greater than the node's key.
Both the left and right subtrees are also binary search trees.


Thought process
    1. Do an inorder traversal, store all the node values into a vector
    2. Since the vector values will be sorted just index the kth value from the vector and return it
    3. indexing kth vector will be vec[k-1] since vector is 0 based index while the tree is 1 based indexed
Time -> O(n) visit each node once Space -> O(n) due to stack in worst case O(h) and result array O(n)

Optimized
    1. Save space from O(n) to O(h) by doing away with the result array and instead tracking the kth node on the go
    2. Also we save time since we return early hence time reduces to O(h + k)
*/

class Solution {
public:
    int kthSmallestVector(TreeNode* root, int k) {
        vector<int> res;
        stack<TreeNode*> s;

        TreeNode* curr = root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }

        return res.at(k - 1);
    }

    int kthSmallestOptimized(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int index {};
        TreeNode* curr = root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop();
            index++;
            if (index == k){
                return curr->val;
            }
            curr = curr->right;
        }

        return -1; // k larger than number of nodes in tree;
    }
};

int main(){
    Solution sol;

    // TestCase 1
    TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));  int k = 1;

    cout << sol.kthSmallestVector(root1, k) << endl;

    cout << sol.kthSmallestOptimized(root1, k) << endl;

    delete root1;

    // TestCase 2
    TreeNode* root2 = new TreeNode(24, new TreeNode(3, new TreeNode(2), nullptr), new TreeNode(5));  k = 4;

    cout << sol.kthSmallestVector(root2, k) << endl;

    cout << sol.kthSmallestOptimized(root2, k) << endl;

    delete root2;

}