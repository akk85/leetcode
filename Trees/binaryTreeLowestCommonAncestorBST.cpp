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
    1. For a bst tree, comparing root with its children, all larger children will be on the rght side and smaller children on the left
    2. therefore if our root node is larger than both of our nodes we go to left subtree,
        * otherwise if our root node is smaller than both of our input nodes, we go to the right tree
        * else the case it's btwn the two nodes * or even equal to one of the nodes, this becomes out lca and we return it 
*/
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2){
        TreeNode* curr = root;
        while(curr){
            if (curr->val > node1->val && curr->val > node2->val){
                curr = curr->left;
            } else if (curr->val < node1->val && curr->val < node2->val){
                curr = curr->right;
            } else {
                return curr; // curr is btwn node1 and node2 or (equal to one of them)
            }
        }
        return nullptr; // assured to never reach here as both node1 and node2 are valid nodes in root tree
    }
    
};

int main(){
    Solution sol;
    // TestCase 1
    TreeNode* root = 
        new TreeNode(5, 
            new TreeNode(3, 
                new TreeNode(1, nullptr, 
                    new TreeNode(2)), 
                        new TreeNode(4)), 
                            new TreeNode(8, 
                                new TreeNode(7), 
                                    new TreeNode(9)));

    TreeNode* node1 = root->left;  // 3
    TreeNode* node2 = root->right; // 8

    TreeNode* ancestor = sol.lowestCommonAncestor(root, node1, node2);

    cout << ancestor->val << endl;
    delete root;

    // TestCase 2
    root = 
        new TreeNode(5, 
            new TreeNode(3, 
                new TreeNode(1, nullptr, 
                    new TreeNode(2)), 
                        new TreeNode(4)), 
                            new TreeNode(8, 
                                new TreeNode(7), 
                                    new TreeNode(9)));

    node1 = root->left;        // 3
    node2 = root->left->right; // 4

    ancestor = sol.lowestCommonAncestor(root, node1, node2);

    cout << ancestor->val << endl;
    delete root;

}