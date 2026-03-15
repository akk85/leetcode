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

class Solution{
public:
    TreeNode* invertTree(TreeNode* root){
        if (!root){
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            swap(curr->left, curr->right);
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
        return root;
    }

    // level by level(left -> right)
    void topDownPrint(TreeNode* TreeRoot){
        if (!TreeRoot){
            return;
        }
        queue<TreeNode* > q;
        q.push(TreeRoot);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            cout << curr->val << " ";
            if (curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
        cout << endl;
    }
};
int main(){
    Solution sol;
    TreeNode* head = 
        new TreeNode(1, 
            new TreeNode(2, 
                new TreeNode(4), 
                    new TreeNode(5)), 
                        new TreeNode(3, 
                            new TreeNode(6), 
                                new TreeNode(7)));

    sol.topDownPrint(head);                           

    TreeNode* newHead = sol.invertTree(head);

    sol.topDownPrint(newHead);
    
    delete head;
}