#include "../common.hpp"

/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
Example 1:

Input: ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]

Output: [null, null, null, true, false, null, true, null, false]
Explanation:
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1); // set = [1]
myHashSet.add(2); // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2); // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2); // set = [1]
myHashSet.contains(2); // return False, (already removed)

*/

struct Node{
    int value;
    Node* next;
    Node(int nodeValue) : value(nodeValue), next(nullptr) {}
};

class MyHashSet {
private:
    vector<Node*> vec;
    int hashFunction(int key){
        int newKey = key % 1000;
        return newKey;
    }
public:
    MyHashSet() : vec(1000) {
        for (int index = 0; index < 1000; index++) {
            vec[index] = new Node(-1);
        }
    }
    void add(int key) {
        int newKey = hashFunction(key);
        
        Node* head = vec[newKey];
        Node* curr = head->next;

        while(curr){
            if (curr->value == key) return;
            curr = curr->next;
        }

        Node* newNode  = new Node(key);
        Node* nextNode = head->next;
        head->next     = newNode;
        newNode->next  = nextNode;
    }
    
    void remove(int key) {
        int newKey = hashFunction(key);
        Node* head = vec[newKey];
        Node* curr = head;

        while(curr->next){
            if (curr->next->value == key){
                Node* candidate = curr->next;
                curr->next= curr->next->next;
                delete candidate;
                return;
            }
            curr = curr->next;
        }
    }
    bool contains(int key) {
        int newKey = hashFunction(key);
        Node* head = vec[newKey];
        Node* curr = head->next;
        while(curr){
            if (curr->value == key) return true;
            curr = curr->next;
        }
        return false;
    }
};