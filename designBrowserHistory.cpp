#include "common.hpp"

/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move 
forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
void visit(string url) Visits url from the current page. It clears up all the forward history.

string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. 
Return the current url after moving back in history at most steps.

string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. 
Return the current url after forwarding in history at most steps.

use doubly linked list
each visit is a new node added to next of currpage
head - pages - tail
*/
struct Node{
    string data;
    Node* next;
    Node* prev;

    Node(string val) : data(val) , next(nullptr), prev(nullptr) {};
};
class BrowserHistory {
private:
    Node* head;
    Node* tail;
    Node* currentPage;
    void deleteForwardHistory(Node* current){
        Node* nextNode = current->next;
        while(nextNode != tail){
            Node* nextnextNode = nextNode->next;
            delete nextNode;
            nextNode = nextnextNode;
        }
        current->next = tail;
        tail->prev = current;
    }
public:
    BrowserHistory(string homepage) {
        head = new Node("head");
        Node* firstNode = new Node(homepage);
        tail = new Node("tail");

        head->next      = firstNode;
        firstNode->next = tail;
        tail->prev      = firstNode;
        firstNode->prev = head;

        currentPage = firstNode;
    }

    ~BrowserHistory() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
    
    void visit(string url) {
        if (currentPage->next != tail){
            deleteForwardHistory(currentPage);
        }

        Node* newNode     = new Node(url);

        currentPage->next = newNode;
        newNode->next     = tail;
        tail->prev        = newNode;
        newNode->prev     = currentPage;

        currentPage       = newNode;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++ ){
            if (currentPage->prev == head){
                break;
            }
            currentPage = currentPage->prev;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++ ){
            if (currentPage->next == tail){
                break;
            }
            currentPage = currentPage->next;
        }
        return currentPage->data;
    }
};

int main(){
    BrowserHistory browser("leetcode.com");

    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");

    cout << browser.back(1) << endl;     // facebook
    cout << browser.back(1) << endl;     // google

    cout << browser.forward(1) << endl;  // facebook

    browser.visit("linkedln.com");

    cout << browser.forward(2) << endl;  // linkedln
    cout << browser.back(2) << endl;     // google

    cout << browser.back(7) << endl;     // leetcode
    cout << browser.forward(7) << endl;     // linkedln
}