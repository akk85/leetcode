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
You are given the root of a binary tree. 

Return only the values of the nodes that are visible from the left side of the tree, ordered from top to bottom.

thought process:
    the left most node is the first node to traverse in each level if traversing from left to right 
    we can traverse each level and get that first node

pseudo code
    vector res
    queue<treenode>
    q.push(root)
    while(qnot empty)
        size = q.size();
        // first node will be first node to trverse in curr queue
        fpr (int i = 0; i < size; i++)
            npde = q.front() qpop
            if i == 0
                res.push(node.val)
            if node.left q push node.left 
            if node.right qpush node right

    return res

    time -> 0(n) for visiting all nodes space overall O(d) where d is biggest diameter of tree o(n) worst case when level is all nodes in tree
*/



class Solution {
public:
    vector<int> leftSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                if (i == 0) res.push_back(node->val);

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
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

    TreeNode* root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3, nullptr, new TreeNode(5)));

    vector<int> result = sol.leftSideView(root);

    printResult(result); // 1 2 4

    delete root;

    root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(5), nullptr), nullptr), new TreeNode(3));

    result = sol.leftSideView(root);

    printResult(result); // 1 2 4 5

    delete root;

    root = new TreeNode(1, nullptr, new TreeNode(2));

    result = sol.leftSideView(root);

    printResult(result); // 1 2

    delete root;

    root = nullptr;

    result = sol.leftSideView(root);

    printResult(result); // {}

    delete root;
}