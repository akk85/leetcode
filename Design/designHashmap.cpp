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
    int value;
    Node* next;
    Node* prev;

    Node(int newkey, int newValue) : key(newkey), value(newValue), next(nullptr), prev(nullptr) {};
};


class MyHashMap {
private:
    unordered_set<int> seen;
    Node* head;
    Node* tail;
public:
    MyHashMap() {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    /*
    h<->3<->t //4
    h<->3->4<->t
    */
    void put(int key, int value) {
        if (seen.count(key)){
            remove(key);
        }

        Node* newNode = new Node(key, value);
        Node* lastNode = tail->prev;
        lastNode->next = newNode;
        newNode->next = tail;
        tail->prev = newNode;
        newNode->prev = lastNode;
        seen.insert(key);
    }

    // h<->3->4<->t        get(4)
    //        c
    int get(int key) {
        if (seen.count(key)){
            Node* curr = head;
            while(curr->key != key){
                curr = curr->next;
            }

            return curr->value;
        }
        return -1;
    }
    // h<->3->4<->t        remove(4)
    //        c
    // h<->3<->t
    void remove(int key) {
        if (seen.count(key)){
            Node* curr = head;
            while(curr->key != key){
                curr = curr->next;
            }
            Node* prevNode = curr->prev;
            Node* nextNode = curr->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete curr;
            seen.erase(key);
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