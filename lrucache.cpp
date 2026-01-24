#include <iostream>
#include <unordered_map>

using namespace std;
struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int nodeKey, int nodeValue) : key(nodeKey),value(nodeValue), prev(nullptr), next(nullptr) {};
};


class LRUCache {
private:
    size_t cap;
    unordered_map<int, Node*> cache;
    Node* head; 
    Node* tail;

    void remove(Node* node){
        Node* previousNode = node->prev;
        Node* nextNode = node->next;
        previousNode->next = nextNode;
        nextNode->prev = previousNode;
    }

/*
    {1, 10}
    {2, 10}
    {3, 30}
    [h]<->[1]<->[2]<->[3]<->[t]
    [h]<->[2]<->[3]<->[t]

*/

    void insert(Node* node){
        Node* lastNode = tail->prev;
        lastNode->next = node;
        node->prev = lastNode;
        node->next = tail;
        tail->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head  = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    ~LRUCache(){
        Node* curr = head;
        while(curr){
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    int get(int key) {
        if (cache.count(key)){
            Node* node = cache[key];
            remove(node);    //remove from it's position and insert it at end as mru 
            insert(node);
            cout << node->value << endl;
            return node->value;
        }
        return -1; // if not found
    }
/*
    {1, 10}
    {2, 10}
[2]
    [h]<->[1]<->[t]

*/
    void put(int key, int value) {
        if (cache.count(key)){
            Node* candidate = cache[key];
            remove(candidate);
            insert(candidate);
            return;
        };

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap){
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

    }
};


int main(){
    LRUCache lRUCache(2);  // cache 
    lRUCache.put(1, 10);  // cache: {1=10}
    lRUCache.get(1);   
    lRUCache.put(2, 20);  
    lRUCache.put(3, 30); 
    lRUCache.get(2);      // returns 20 
    lRUCache.get(1);      // return -1 (not found)
}