#include "../common.hpp"

class Node{
public:
    int value;
    Node* next;

    Node(int nodeValue) : value(nodeValue), next(nullptr) {};
    Node(int nodeValue, Node* nextNode) : value(nodeValue), next(nextNode) {};
    ~Node(){
        value = 0;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head = nullptr;
public:
    LinkedList() {}
    /*
    3->5->7->9
             c
             i 
    */
    int get(int index){
        if (!head){
            return -1;
        }

        Node* curr = head;
        int i = 0;
        while (i != index && curr){
            curr = curr->next;
            i++;
        }

        if (!curr){
            return -1;
        }

        return curr->value;

    }

    void insertHead(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int value){
        if (!head){
            insertHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* curr = head;

        while (curr && curr->next){
            curr = curr->next;
        }
        curr->next = newNode;
    }

    bool remove(int index){
        if (!head){
            return false;
        }

        Node* curr = head;
        int i = 0;
        while (i + 1 != index && curr){
            curr = curr->next;
            i ++;
        }

        if (!curr){
            return false;
        }
        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;

        return true;
    }

    vector<int> getValues(){
        if (!head){
            return {};
        }
        vector<int> res;
        Node* curr = head;
        while(curr){
            res.push_back(curr->value);
            curr = curr->next;
        }

        return res;
    }
};

int main(){
    LinkedList list;
    list.insertHead(7);
    list.insertHead(5);
    list.insertHead(9);

    cout << list.get(0) << endl;
    cout << list.get(1) << endl;
    cout << list.get(2) << endl;

}