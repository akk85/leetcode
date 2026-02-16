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
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

thought process:
    1; do bfs using queue and count each level return level 
    1. since we cant reach the parent node of a node from the node itself, we can thimk to structure this tree like a undirected graph where from a node we can reach all of its neighbors (left right and parent node)
    2. we can map out each node to its' parent
    3. as we do bfs from the start node, visit all left right and parent node, mark them as visted and makr time as 1
    repeate for all nodes until all nodes in tree have been visited

pseudo code
    1.bfs to map node to parent
    unordered_map<node, node> map
    queue<node> root
    while queue:
        node = queue.pop
        if node == start
            startNode = node
        if node has left
            map[node.left] = node
            queue .push(left)
        if node has right
            map[node.right] = node
            queue.push(rightnode)
        
    1. bfs to vist nodes and find time
    queue.push(startnode)
    visited.add(startnode)
    int time = -1;
    while queue:
        for (all nodes in current queue)
            node = q.pop()
            if node.left and not visited
                q.push(node.left)
                visted.add(leftnode)
            if node.right and not visited
                q.push(node.right)
                visited.add(rightnode)
            if map[node] and not visited
                q.push(parent)
                visited.add(parent)
        time += 1;
    
    return time;


*/



class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        
        // 1. bfs for parent mapping
        unordered_map<TreeNode*, TreeNode*> map; // child -> parent
        TreeNode* startNode = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();  q.pop();
            if (node->val == start){
                startNode = node;
            }

            if (node->left){
                map[node->left]  = node;
                q.push(node->left);
            }
            if (node->right){
                map[node->right] = node;
                q.push(node->right);
            }
        }

        // 2. bfs to visit all connected nodes 
        unordered_set<TreeNode*> visited;
        q.push(startNode);
        visited.insert(startNode);
        int minutes = -1;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                // left right and parent
                if (node->left && !visited.contains(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.contains(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                if (map.contains(node) && !visited.contains(map[node])){
                    TreeNode* parent = map[node];
                    q.push(parent);
                    visited.insert(parent);
                }
            }
            minutes += 1;
        }

        return minutes;
    }
};

int main(){
    Solution sol;
    // TestCase 1
    TreeNode* root =    new TreeNode(1, new TreeNode(5, nullptr, new TreeNode( 4,new TreeNode(9),new TreeNode(2))),
                        new TreeNode(3, new TreeNode(10), new TreeNode(6)));


    cout << sol.amountOfTime(root, 3) << endl;
    delete root;

    // TestCase 2
    root = new TreeNode(1);
    cout << sol.amountOfTime(root, 1) << endl;
    delete root;
}

