#include "common.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 thought process
    start from root do bfs tracking each child node with previous node eg 4,9,5 when we reach to a node with no children just
    push this value to a result array as an int so 4,9,5 becomes 495 do so for all leaf nodes and 
    at end of bfs just add the int values in the vector and return that 

        * instead of vector which will be 0(d) where d is the diameter of the tree we can just use a running total which is consnt memory

pesudeo code
    int total  = 0
    start from root
        push root to queue with it's value 
        while queue
            pop node from queue
            if children append child with node* 10 + childvalue to queue
            if leaf take node value and add it to running total 

        
 */
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

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int total {};
        queue<pair<TreeNode*, int >> q;

        q.push({root, root->val});

        while(!q.empty()){
            pair<TreeNode*, int> currPair = q.front(); q.pop();
            TreeNode* currNode = currPair.first;
            int currValue = currPair.second;
            if (currNode->left){
                q.push({currNode->left, currValue * 10 + currNode->left->val});
            } 
            if (currNode->right){
                q.push({currNode->right, currValue * 10 + currNode->right->val});
            }

            if (!currNode->left && !currNode->right){
                total += currValue;
            }

        }
        return total;

    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << sol.sumNumbers(root) << endl;

    delete root;

    // [4,9,0,5,1]

    root = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    
    cout << sol.sumNumbers(root) << endl;

    delete root;
}