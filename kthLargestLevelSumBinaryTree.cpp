#include "common.hpp"

/*
You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

thought process:
    I could traverse the tree using bfs to get sum at each level and append sum to a min heap
    If heap size becomes greater than k:
        pop minimum root elemnent
    at the end
        * if heap size is less than k return -1 else return root of heap which holds kth max value 

    time = 0(n) for traversing all nodes and space is O(n) where
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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()){
            int size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }
            }
            minHeap.push(sum);
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        if (minHeap.size() < k){
            return -1;
        }
        
        return minHeap.top();
    }


};

int main(){
    Solution sol;

    TreeNode* root =
        new TreeNode(5,
            new TreeNode(8,
                new TreeNode(2,
                    new TreeNode(4),
                        new TreeNode(6)),
                            new TreeNode(1)),
                               new TreeNode(9,
                                    new TreeNode(3),
                                         new TreeNode(7)));

    cout << sol.kthLargestLevelSum(root, 2) << endl;

    delete root;

}