

/*

{1, Node} Node (int key, int value, Node* prev, Ndoe* next)
{2, Node}
{3, Node}

map[key].value 

h<-3->4<->5<->t


h<->4<->5<->t
node 4
*/
#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;


    Node(int NodeKey, int NodeValue) : key(NodeKey), val(NodeValue), prev(nullptr), next(nullptr) {};
};

class LRUCache{
private:
    size_t cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // h<-3->1<->5<->t
    // h<-3<->5<->t

    void remove(Node* node){
        Node* previousNode = node->prev;
        Node* nextNode = node->next;

        previousNode->next = nextNode;
        nextNode->prev = previousNode;
    }

    // h<-3<->5<->t         1
    // h<-3<->5<->1<->t
    void insert(Node* node){
        Node* lastNode = tail->prev;
        lastNode->next = node;
        node->next = tail;
        node->prev = lastNode;
        tail->prev = node;
    }
public:
/*
    {1, Node}

    h<-3->1<->5<->t

    remove
    1
    h<-3<-->5<->1<->t


    0<->0
*/
    LRUCache(int capacity){
        cap = capacity;
        
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache(){
        while(head){
            Node* nextNode = head->next;
            delete head;
            head = nextNode;
        }
        cache.clear();
    }

    int get(int key){
        if (cache.count(key)){
            Node* newNode = cache[key];
            remove(newNode);  // from current position
            insert(newNode);  // insert it at end of out list to mark it as MRU 

            return newNode->val;
        }

        return -1;
    }

    // {3, Node}
    // {5, Node}
    // (1, Node)
    
    // h<-3<->1<->5<->t.  put (5, value)

    void put(int key, int value){
        // if key exists update the key with new value
        if (cache.count(key)){
            Node* candidate = cache[key];
            cache[key]->val = value;
            remove(candidate);
            insert(candidate);
            return;
        }

        // if key doesn't exist create new node with key and value
        Node* newNode = new Node(key, value);
        cache[key] = newNode;   
        insert(newNode);

        // if current cache capacity is greater than cap, we need to remove LRU node will be at the head 
        if (cache.size() > cap){
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

    // {5, Node}
    // (1, Node)
    // {4, Node}

// h<->1<->5<->4<->t  put(4, value); cap(3)

int main(){

    LRUCache cache(3);
    cout << cache.get(0) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(5) << endl;

    cache.put(1, 10);
    cache.put(3, 15);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;  
    
    cache.put(3, 20);
    cout << cache.get(3) << endl;  
    
    // cache.put(5, 20);
    // cache.put(7, 25);

    // cout << cache.get(1) << endl;
    // cout << cache.get(3) << endl;
    // cout << cache.get(5) << endl;
    // cout << cache.get(7) << endl;

}