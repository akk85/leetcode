#include "common.hpp"


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        createAndMapOldToCopy(head);
        linkOldToCopy(head);
        return oldToCopy[head];
    }

private:
    unordered_map<Node*, Node*> oldToCopy;
    void createAndMapOldToCopy(Node* head){
        oldToCopy[nullptr] = nullptr;

        Node* curr = head;
        while (curr != nullptr){
            Node* copyNode = new Node(curr->val);
            oldToCopy[curr] = copyNode;
            curr =curr->next;
        }
    }
    void linkOldToCopy(Node* head){
        Node* curr = head;
        while (curr){
            Node* copy   = oldToCopy[curr];
            copy->next   = oldToCopy[curr->next];
            copy->random = oldToCopy[curr->random];
            curr = curr->next;
        }
    }
};

/*
old nodes = Copy nodes
3 - 3
7 - 7
4 - 4
5 - 5
null - null

3 - 7
*/