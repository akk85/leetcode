#include "../common.hpp"

/*
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

Thought process:
    use a hashmap of freq -> node
    and use a doubly linked list for each string and its count
    newer strings entry get added at head 
    min freq at head max freq at tail
*/

struct Node{
    int freq;
    unordered_set<string> seen;
    Node* next;
    Node* prev;
    Node(int NodeFrequency = 0){
        freq = NodeFrequency;
        next = nullptr;
        prev = nullptr;
    }
};
class AllOne {
private:
    unordered_map<string, Node*> store;
    Node* head;
    Node* tail;
    void createnewNode(Node* current, string key, int frequency){
        Node* newNode = new Node(frequency);
        newNode->seen.insert(key);

        Node* nextNode = current->next;
        current->next  = newNode; newNode->next = nextNode;
        nextNode->prev = newNode; newNode->prev = current;
    }
    void addkeytoNode(Node* current, string key){
        current->seen.insert(key);
    }

    void deleteNode(Node* current){
        Node* prevNode = current->prev;
        Node* nextNode = current->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
public:
    AllOne() {
        head = new Node(0);
        tail = new Node(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }
    
    // key not in map -> add to map -> if node count not present create new node else add to node
    // key in map -> remove it from old node, add to new node  
    //            -> if new count not in node create new node else add to that node
    //            -> if only node in curr node delete that node
    void inc(string key) {
        if (!store.contains(key)){
            int frequency = 1;
            if (head->next->freq != 1){
                createnewNode(head, key, frequency);
                store[key] = head->next;
            }
            else {
                addkeytoNode(head->next, key);
                store[key] = head->next;
            }
        }
        else {
            Node* currNode = store[key];
            int newFrequency = currNode->freq + 1;
            currNode->seen.erase(key);

            if (currNode->next->freq != newFrequency){
                createnewNode(currNode, key, newFrequency);
                store[key] = currNode->next;
            }
            else {
                currNode->next->seen.insert(key);
                store[key] = currNode->next;
            }

            // delete node if freq becomes zero
            if (currNode->seen.empty()){
                deleteNode(currNode);
            }
        }
    }

    // if newfreq == 0 remove from node set and delete from hashmap
    // else if newfreq not in nodes create new node else add to existing node
    // if currNode set empty remove node from nodes 
    void dec(string key) {
        Node* currNode   = store[key];

        int newFrequency = currNode->freq - 1;
        currNode->seen.erase(key);
        if (newFrequency == 0){
            store.erase(key);
        }
        else {
            if (currNode->prev->freq == newFrequency){
                addkeytoNode(currNode->prev, key);
                store[key] = currNode->prev;
            }
            else {
                createnewNode(currNode->prev, key, newFrequency);
                store[key] = currNode->prev;
            }
        }
        if (currNode->seen.empty()){
            deleteNode(currNode);
        }
    }
    
    string getMaxKey() {
        if (tail->prev != head){
            return *tail->prev->seen.begin();
        }
        return "";
    }
    
    string getMinKey() {
        if (head->next != tail){
            return *head->next->seen.begin();
        }
        return "";
    }
};

int main(){
    AllOne sol;

    sol.inc("a");
    cout << sol.getMinKey() << endl;     // a
    cout << sol.getMaxKey() << endl;     // a

    sol.inc("a");
    sol.inc("b");
    cout << sol.getMinKey() << endl;     // b
    cout << sol.getMaxKey() << endl;     // a


}