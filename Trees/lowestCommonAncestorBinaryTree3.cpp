#include "../common.hpp"

/*
You are given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T 
is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."
*/
struct Node {
    int val;
    Node *left;
    Node *right;
    Node* parent;
};

// 0(h) space and time
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> nodepParents;

        Node* node = p;
        while(node){
            nodepParents.insert(node);
            node = node->parent;
        }

        node = q;
        while(node){
            if (nodepParents.contains(node)){
                return node;
            }
            node = node->parent;
        }

        return nullptr;
    }
};
