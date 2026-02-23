#include "common.hpp"

// Tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.


can do a post order iterative so for each node we want to make two decision 
        1. rob itself and not rob its children 
        2. not rob itself and either rob left child or not it or rob right child or not rob it
                int notRob = max(robleft, notRobleft) + max(robright, notRobright)

        so for each node we can store in a map a pair of rob and notRob values and have their parents make a decisoon based on that

pseudo code     
    for each node in tree, we have to visit its children first before we can make a decison whether to rob it ot not

    use a stack with a visited boolean
    if a popped node boolean is false we push itself and its children to stack and mark it as visited
    if a popped node flab is true we have visited its children and we can get its rob and not rob decision based on its children rob and not rob
*/


class Solution {
private:
    unordered_map<TreeNode*, pair<int, int>> map;  // node -> {rob, notRob}
public:
    int rob(TreeNode* root) {
        
        stack<pair<TreeNode*, bool>> stack;

        stack.push({root, false});

        while (!stack.empty()){
            auto [node, childrenVisited] = stack.top(); stack.pop();

            if (!node) continue;

            if (childrenVisited){
                int robLeft     = 0; int notRobLeft  = 0;
                int robRight    = 0; int notRobRight = 0;

                if (node->left) {
                    robLeft     = map[node->left].first;
                    notRobLeft  = map[node->left].second;
                }

                if (node->right){
                    robRight    = map[node->right].first;
                    notRobRight = map[node->right].second;
                }

                int nodeRob    = node->val + notRobLeft + notRobRight;
                int nodeNotRob = max(robLeft, notRobLeft) + max(robRight, notRobRight);

                map[node] = {nodeRob, nodeNotRob};
            }
            else {
                stack.push({node, true});
                stack.push({node->right, false});
                stack.push({node->left,  false});
            }
        }

        int robRoot    = map[root].first; 
        int notRobRoot = map[root].second;

        return max(robRoot, notRobRoot);
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(3, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(3, nullptr, new TreeNode(1)));

    cout << sol.rob(root) << endl;

    root = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(3)), new TreeNode(5, nullptr, new TreeNode(1)));

    cout << sol.rob(root) << endl;

    delete root;
}