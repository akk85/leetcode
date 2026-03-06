#include "../common.hpp"

struct Node {
    int key;
    int value;
    int freq = 1;                   
    Node* next;
    Node* prev;

    Node(int nodeKey, int nodeValue) : key(nodeKey), value(nodeValue), next(nullptr), prev(nullptr) {};
};

struct FreqList {
    Node* head;
    Node* tail;

    FreqList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
};

class LFUCache {
private:
    size_t capacity;
    int minFreq;
    unordered_map<int, Node*>      keyNodeMap;   
    unordered_map<int, FreqList*>  freqListMap;  

    void insertNode(FreqList* frqList, Node* node){
        Node* beforeTail      = frqList->tail->prev;
        beforeTail->next      = node;
        node->next            = frqList->tail;
        frqList->tail->prev   = node;
        node->prev            = beforeTail;
    }

    void removeNode(Node* node){
        Node* beforeNode = node->prev;
        Node* afterNode  = node->next;

        beforeNode->next = afterNode;
        afterNode->prev  = beforeNode;
        node->prev = nullptr;
        node->next = nullptr;
    }

    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        removeNode(node);
        
        if (freqListMap[oldFreq]->head->next == freqListMap[oldFreq]->tail) {
            if (minFreq == oldFreq) minFreq++;
        }

        node->freq++;
        if (freqListMap.find(node->freq) == freqListMap.end()) {
            freqListMap[node->freq] = new FreqList();
        }
        insertNode(freqListMap[node->freq], node);
    }

public:
    LFUCache(int newCapacity) {
        capacity = newCapacity;
        minFreq  = 0;
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        if (keyNodeMap.count(key)) {
            Node* node = keyNodeMap[key];
            updateFreq(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyNodeMap.count(key)) {
            Node* node = keyNodeMap[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (keyNodeMap.size() >= capacity) {
            FreqList* list = freqListMap[minFreq];
            Node* LRU = list->head->next;
            keyNodeMap.erase(LRU->key);
            removeNode(LRU);
            delete LRU;
        }

        Node* newNode = new Node(key, value);
        keyNodeMap[key] = newNode;
        minFreq = 1;
        if (freqListMap.find(1) == freqListMap.end()) {
            freqListMap[1] = new FreqList();
        }
        insertNode(freqListMap[1], newNode);
    }
};

int main(){
    LFUCache cache(2);

    cout << cache.get(1) << endl; // -1 
    cache.put(1,1);
    cache.put(2,2);

    cout << cache.get(1) << endl; // 1
    cache.put(3,3);

    cout << cache.get(2) << endl; // -1

    cout << cache.get(3) << endl; // 3

    cache.put(4,4);

    cout << cache.get(1) << endl; // -1

    cout << cache.get(3) << endl; // 3

    cout << cache.get(4) << endl; // 4

    return 0;
}