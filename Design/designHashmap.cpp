#include "../common.hpp"

/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.

void put(int key, int value) inserts a (key, value) pair into the HashMap. 
If the key already exists in the map, update the corresponding value.

int get(int key) returns the value to which the specified key is mapped, 
or -1 if this map contains no mapping for the key.

void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
*/
struct Node{
    int key;
    int val;
    Node* next;
    Node(int nodeKey, int nodeValue) : key(nodeKey), val(nodeValue), next(nullptr) {}
};

class MyHashMap {
private:
    vector<Node*> vec;
    int hashFunction(int key){
        int newKey = key % 1000;
        return newKey;
    }
public:
    MyHashMap() : vec(1000) {
        for (int index = 0; index < 1000; index++) {
            vec[index] = new Node(-1, -1);
        }
    }
    
    void put(int key, int value) {
        int newKey = hashFunction(key);
        Node* head = vec[newKey];
        Node* curr = head->next;

        while(curr){
            if (curr->key == key) {
                curr->val = value;
                return;
            }
            curr = curr->next;
        }
        Node* newNode  = new Node(key, value);
        Node* nextNode = head->next;
        head->next     = newNode;
        newNode->next  = nextNode;
    }
    
    int get(int key) {
        int newKey = hashFunction(key);
        Node* head = vec[newKey];
        Node* curr = head->next;

        while(curr){
            if (curr->key == key) return curr->val;
            curr = curr->next;
        }

        return -1;

    }
    
    void remove(int key) {
        int newKey = hashFunction(key);
        Node* head = vec[newKey];
        Node* curr = head;

        while(curr->next){
            if (curr->next->key == key){
                Node* candidate = curr->next;
                curr->next= curr->next->next;
                delete candidate;
                return;
            }
            curr = curr->next;
        } 
    }
};

int main(){
    MyHashMap* obj = new MyHashMap();
    obj->put(1,1);
    cout << obj->get(1) << endl;     // returns 1
    
    obj->put(2,2);
    cout << obj->get(2) << endl;     // returns 2
    cout << obj->get(3) << endl;     // returns -1

    obj->put(2,5);
    cout << obj->get(2) << endl;     // returns 5 updated value 

    obj->remove(1);
    cout << obj->get(1) << endl;     // returns -1 key 1 is removed;
}
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */