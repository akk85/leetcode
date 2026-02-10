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
    1. Iterate over the whole tree and create a map of each node maped to its parent 
    2. grab all ancestors of node1 begining from itself all the way to the root and put them in a set or array
    3. iterating over ancestors of node2, if we happen to encounter for the first time an ancestor of node2 that is 
        in the set of node2 ancestors this becomes our lca and we return it.
        we are assured that node1 and node2 will exist in our main tree

    Time -> going through all nodes in tree to grab parent is O(n) and then building the set of ancestors at most would be 
    0(h) and iterating over ancestors of node2 will also be o(h) overall time complexity is O(n)
    Space -> we will be storing in the ancestor map a node and it's parent hence worst case O(2 * n) -> O(n)
    set will be O(h) overall O(n) extra space needed
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2) {
        unordered_map<TreeNode*, TreeNode*> map;
        map[root] = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        // 1. Build parent map
        while (!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if (node->left){
                map[node->left] = node;
                q.push(node->left);
            }
            if (node->right){
                map[node->right] = node;
                q.push(node->right);
            }
        }

        // 2. get ancestors of node1
        unordered_set<TreeNode*> node1Ancestors;
        while(node1){
            node1Ancestors.insert(node1);
            node1 = map[node1];
        }

        while(node2){
            if (node1Ancestors.contains(node2)){
                return node2;
            }
            node2 = map[node2];
        }

        return nullptr; // we are assured never to reach here by the problem statetement
    }
};

int main(){
    Solution sol;
    TreeNode* root = 
            new TreeNode(3, 
                new TreeNode(5, 
                    new TreeNode(6), 
                        new TreeNode(2, 
                            new TreeNode(7), 
                                new TreeNode(4))), 
                                    new TreeNode(1, 
                                        new TreeNode(0), 
                                            new TreeNode(8)));

    TreeNode* node1 = root->left->left;
    TreeNode* node2 = root->right->right;

    TreeNode* ancestor = sol.lowestCommonAncestor(root, node1, node2);

    cout << ancestor->val << endl;

    delete root;

}