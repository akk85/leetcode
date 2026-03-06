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
Thought process
    1. do a bfs traversal level by level using a queuee
    2. at beginning of each queue traversal, the queue will only contain nodes of same level
    3. iterate over all this nodes, put them in a list and add this list to our global return list 



        1
    2       3
4      5 6     7
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int length = q.size();
            vector<int> levelVector;
            for (int i = 0; i < length; i++){
                TreeNode* node = q.front(); q.pop();
                levelVector.push_back(node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            res.push_back(levelVector);
        }

        return res;
    }

    void print(vector<vector<int>>& levels){
        for (const auto& level : levels){
            for (int x : level){
                cout << x << " ";
            }
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1,new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));

    vector<vector<int>> result = sol.levelOrder(root);

    sol.print(result);

    delete root;
}