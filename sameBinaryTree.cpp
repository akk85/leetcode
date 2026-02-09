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

class Solution{
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        if (root1 == nullptr && root2 == nullptr){
            return true;
        }

        if (root1 == nullptr || root2 == nullptr){
            return false;
        }

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
 1              1
2 3            2 3 

*/

int main(){
    Solution sol;

    TreeNode* root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));

    cout << boolalpha << sol.isSameTree(root1, root2) << endl;

    delete root1;
    delete root2;
}