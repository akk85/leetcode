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
Thought process:
    1. find the node corresponding to root node of subtree
    2. begging from this two same nodes check if rest of the trees are same by traversing bfs
        . we dont imedialtely return nut continue sarching incase tree has other same nodes with same values as subtree root.
    3. if we never found the subtree root in main tree we return false;
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)     return false;
        if (!subRoot) return true;
        // find the subroot root in main tree;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();

            if (node->val == subRoot->val){
                if (isSameTree(node, subRoot)){
                    return true;
                }
            }
            if (node->left){
                q.push(node->left);
            }
            if (node->right){
                q.push(node->right);
            }
        }
        return false;
    }
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        queue<pair<TreeNode*, TreeNode* >> q;
        q.push({root1, root2});

        while (!q.empty()){
            auto [node1, node2] = q.front(); q.pop();

            if (node1 == nullptr && node2 == nullptr){
                continue;
            }
            if (node1 == nullptr || node2 == nullptr || node1->val != node2->val){
                return false;
            }
            q.push({node1->left,  node2->left});
            q.push({node1->right, node2->right});
        }
        return true;
    }
};

/*
        1
    2       3
4       5

    2
4       5
*/
int main(){
    Solution sol;

    // first test case 
    TreeNode* root    = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    TreeNode* subRoot = new TreeNode(2, new TreeNode(4), new TreeNode(5));

    cout << boolalpha << sol.isSubtree(root, subRoot) << endl;

    delete root;
    delete subRoot;

    // second test case
    TreeNode* root2 = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(6), nullptr), new TreeNode(5)), new TreeNode(3));
    TreeNode* subRoot2 = new TreeNode(2, new TreeNode(4), new TreeNode(5));

    cout << boolalpha << sol.isSubtree(root2, subRoot2) << endl;

    delete root2;
    delete subRoot2;

    TreeNode* root3 = new TreeNode(1, new TreeNode(1), nullptr);
    TreeNode* subRoot3 = new TreeNode(1);

    cout << boolalpha << sol.isSubtree(root3, subRoot3) << endl;

}