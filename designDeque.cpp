#include "common.hpp"

class Node{
public:
    Node* next;
    int value;
    Node* prev;

    Node(int nodeValue) : next(nullptr), value(nodeValue), prev(nullptr) {};
};
class Deque{
private:
    Node* head;
    Node* tail;
public:
    Deque() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    ~Deque(){
        Node* curr = head;
        while (curr != nullptr){
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty() {
        return head->next == tail;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        Node* lastNode = tail->prev;

        lastNode->next = newNode;
        newNode->next = tail;

        newNode->prev = lastNode;
        tail->prev = newNode;
    }
/*
h->5->3<->t
       5
*/
    void appendleft(int value) {
        Node* newNode = new Node(value);
        Node* firstNode = head->next;

        newNode->next = firstNode;
        head->next = newNode;

        newNode->prev = head;
        firstNode->prev = newNode;
    }

    int pop() {
        if (isEmpty()){
            return -1;
        }

        Node* lastNode = tail->prev;
        int lastNodeValue = lastNode->value;

        lastNode->prev->next = tail;
        tail->prev = lastNode->prev;

        delete lastNode;

        return lastNodeValue;
    }

    int popleft() {
        if (isEmpty()){
            return -1;
        }
        Node* firstNode = head->next;
        int firstNodeValue = firstNode->value;

        head->next = head->next->next;
        firstNode->next->prev = head;

        delete firstNode;
        return firstNodeValue;
    }

    void printValues(){
        if (isEmpty()){
            return;
        }
        Node* curr = head->next;
        while(curr != tail){
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
        return;
    }
};

int main(){
    Deque deque;

    cout << boolalpha << deque.isEmpty() << endl;

    deque.append(10);
    deque.append(20);
    deque.printValues();


    deque.appendleft(5);
    deque.printValues();

    deque.pop();
    deque.printValues();

    deque.popleft();
    deque.printValues();
}

/*
h<->3<->t
        c
h<->t
*/