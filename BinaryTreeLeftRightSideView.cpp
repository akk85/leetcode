#include "common.hpp"

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
You are given the root of a binary tree.

Return the values of the nodes that are visible when the tree is viewed from the outer boundary at each level — specifically:

The leftmost node at every level.

The rightmost node at every level.

If a level contains only one node, it should only be counted once.

Return the result in level-order (top to bottom).

Intution:
    I would do a bfs search going level by level at each level grab the left node and the right node
        * to avoid duplicates if both left and right are same meaning one node in that level i will just push left to the result array
        * otherwise push both left and right node
        * after tree traversal return the nodes
        * 
    Time ->O(n) as we are traversing each node in tree once and Space -> O(n) for the result vector and queue incase all levels are 
    of one node meaning we store all nodes in our result
    
pseudo code:
    if (!root) return {}
    queue.push(root)
    int leftnode = root.val
    int rightnode = root.val
    while queue:
        int size = q.size
        for (int i = 0; i < szie; i++)
            node = q.pop
            if (i == 0) leftnode = node.val
            if (i = size - 1) rightnode = node.val
            if (node.left) q.push(node.left)
            if (node.right) q.push(node.right)
        
        if (leftnode == rightnode) res.append(leftnode)
        else res.append(leftnode) res.append(rightnode)

    return res

*/


class Solution {
public:
    vector<int> LeftRightSideView(TreeNode* root){
        if (!root) return {};

        vector<int> res;
        int leftNode  = root->val;
        int rightNode = root->val;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if (i == 0)        leftNode  = node->val;
                if (i == size - 1) rightNode = node->val;

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (size == 1) {
                res.push_back(leftNode);
            }
            else {
                res.push_back(leftNode);
                res.push_back(rightNode);
            }
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

    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));     

    vector<int> result = sol.LeftRightSideView(root);
    printResult(result);    // 2 1 3 

    delete root;

    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3, new TreeNode(5, new TreeNode(7), nullptr), new TreeNode(6)));

    result = sol.LeftRightSideView(root); // 1 2 3 3 4 6 7
    printResult(result);
    delete root;

}

