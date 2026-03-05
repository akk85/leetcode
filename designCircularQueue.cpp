#include "common.hpp"

/*
Design and implement circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.

use Doubly linked list
    append at tail
    remove from head
*/

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int nodeValue) : val(nodeValue), next(nullptr), prev(nullptr) {}; 
};
class MyCircularQueue {
private:
    Node* head;
    Node* tail;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        head = new Node(-1);
        tail = new Node(-1);

        head->next = tail;
        tail->prev = head;

        size = 0;
        capacity = k;
    }

    ~MyCircularQueue() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);
        Node* lastNode = tail->prev;

        lastNode->next = newNode;
        newNode->next  = tail;
        tail->prev     = newNode;
        newNode->prev  = lastNode;

        size ++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        Node* firstNode = head->next;

        head->next = firstNode->next;
        firstNode->next->prev = head;

        delete firstNode;
        size --;

        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;

        return head->next->val;
    }
    
    int Rear() {
        if (isEmpty()) return -1;

        return tail->prev->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        if (size == capacity) return true;

        return false;
    }
};


int main(){
    MyCircularQueue queue(3);

    cout << boolalpha << queue.enQueue(1) << endl; // true
    cout << boolalpha << queue.enQueue(2) << endl; // true
    cout << boolalpha << queue.enQueue(3) << endl; // true
    cout << boolalpha << queue.enQueue(4) << endl; // false

    cout << queue.Rear() << endl; // 3
    cout << boolalpha << queue.isFull() << endl;   // true
    cout << boolalpha << queue.deQueue() << endl;  // true
    cout << boolalpha << queue.enQueue(4) << endl; // true
    cout << queue.Rear() << endl; // 4
}