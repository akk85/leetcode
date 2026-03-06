#include <iostream>
#include <unordered_set>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node() : data(0), prev(nullptr),  next(nullptr) {};
    Node(int x) : data(x), prev(nullptr), next(nullptr) {};
    Node(int x, Node* prevNode, Node* nextNode) : data(x), prev(prevNode), next(nextNode) {};
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {};
    LinkedList(Node* headNode) : head(headNode) {};

    ~LinkedList(){
        unordered_set<Node* > seen;
        Node* curr = head;
        while(curr && !seen.count(curr)){
            seen.insert(curr);
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = nullptr;

    }

    Node* getHead() const {
        return head;
    }
};

// Nodes in forward order
void printNodesForward(const Node* head){
    unordered_set<const Node* > seen;
    if (!head){
        return;
    }
    const Node* curr = head;
    while(curr && seen.count(curr)){
        cout << curr->data << " ";
        seen.insert(curr);
        curr = curr->next;
    }
    cout << endl;
}

// Nodes in reverse order 10<->20<->30<->40<->50
void printNodesReverse(const Node* head){
    if (!head){
        return;
    }
    const Node* curr = head;
    while(curr->next){
        curr = curr->next;
    }

    while (curr){
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}
// Length of Linked List
int getLength(const Node* head){
    if (!head){
        return 0;
    }
    int count {};
    const Node* curr = head;
    while (curr){
        count ++;
        curr = curr->next;
    }
    return count;
}

// Search in Linked List(int x)
bool contains(const Node* head, int x){
    if (!head){
        return false;
    }
    const Node* curr = head;
    while (curr){
        if (curr->data == x){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Find Middle of Linked List
// 10<->20<->30<->40<->50<->60
//                 s
//                              f
const Node* findMiddle(const Node* head){
    if(!head){
        return nullptr;
    }
    const Node* slow = head;
    const Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
// 10<->20<->30<->40<->50
// Find Tail Node
const Node* findTail(const Node* head){
    if (!head){
        return nullptr;
    }
    const Node* curr = head;
    while(curr->next){
        curr = curr->next;
    }
    return curr;
}
// <-10<-20<->30<->40<->50
// c
// Reverse Linked List
Node* reverseList(Node* head){
    if (!head || !head->next){
        return head;
    }

    Node* curr    = head;
    Node* newHead = nullptr;

    while(curr){
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        newHead = curr;
        curr = curr->prev;
    }

    return newHead;

}
// 10<-20<->30<->30<->20<->10
//          t
//               h
// Check if Linked List is a Palindrome
bool ispalindrome(const Node* head){
    if (!head){
        return true;
    }

    // step 1: find tail
    const Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }

    // compare from end to beginning 
    while(head && tail && head != tail && head->prev != tail){
        if (head->data != tail->data){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;

}

// Remove Duplicates from Sorted Linked List
// 10<->10<->30<->40<->40
// 10<-->30<->40<->40
// c
Node* removeDuplicatesSorted(Node* head){
    if (!head || !head->next){
        return head;
    }
    Node* curr = head;
    while(curr && curr->next){
        if (curr->data == curr->next->data){
            Node* toRemove = curr->next;
            Node* toRemoveNext = toRemove->next;
            if (toRemoveNext){
                toRemoveNext->prev = curr;
            }
            curr->next = toRemoveNext;
            delete toRemove;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

// Detect Cycle in Linked List naive O(n) space
bool hasCycleBruteForce(const Node* head){
    if(!head || !head->next){
        return false;
    }
    unordered_set<const Node*> seen;
    const Node* curr = head;
    while(curr){
        if (seen.count(curr)){
            return true;
        }
        seen.insert(curr);
        curr = curr->next;
    }
    return false;
}
// Detect Cycle in Linked List O(1) space
bool hasCycle(const Node* head){
    if (!head || !head->next){
        return false;
    }
    const Node* slow = head;
    const Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            return true;
        }
    }
    return false;
}

Node* createNodes1(){
    Node* node5 = new Node(10, nullptr, nullptr);
    Node* node4 = new Node(20, nullptr, node5);
    node5->prev = node4;
    Node* node3 = new Node(30, nullptr, node4);
    node4->prev = node3;
    Node* node2 = new Node(20, nullptr, node3);
    node3->prev = node2;
    Node* node1 = new Node(10, nullptr, node2);
    node2->prev = node1;

    return node1;
}

Node* createNodes2(){
    Node* node5 = new Node(40, nullptr, nullptr);
    Node* node4 = new Node(40, nullptr, node5);
    node5->prev = node4;
    Node* node3 = new Node(30, nullptr, node4);
    node4->prev = node3;
    Node* node2 = new Node(10, nullptr, node3);
    node3->prev = node2;
    Node* node1 = new Node(10, nullptr, node2);
    node2->prev = node1;

    return node1;
}

Node* createNodes3(){
    Node* node5 = new Node(40, nullptr, nullptr);
    Node* node4 = new Node(40, nullptr, node5);
    node5->prev = node4;
    Node* node3 = new Node(30, nullptr, node4);
    node4->prev = node3;
    Node* node2 = new Node(10, nullptr, node3);
    node3->prev = node2;
    Node* node1 = new Node(10, nullptr, node2);
    node2->prev = node1;
    node5->next = node1;
    node1->prev = node5;

    return node1;
}
int main(){


    Node* node1 = createNodes1();
    LinkedList list(node1);
    Node* head = list.getHead();
    cout << "Nodes in Forward Order: ";
    printNodesForward(head);
    cout << "Nodes in Reverse Order: ";
    printNodesReverse(head);

    cout << "Length of list: " << getLength(head) << endl;
    
    cout << "List contains the node x: " << boolalpha << contains(head, 50) << endl;
 
    cout << "Middle Node: " << findMiddle(head)->data << endl;
    cout << "Tail Node: " << findTail(head)->data << endl;

    cout << "List is a palindrome: " << boolalpha << ispalindrome(head) << endl;

    cout << "Before Removing Duplicates: ";
    Node* node2 = createNodes2();
    LinkedList list2(node2);
    Node* newHead = list2.getHead();
    printNodesForward(newHead);
    
    removeDuplicatesSorted(newHead);
    cout << "After Removing Duplicates: ";
    printNodesForward(newHead);

    Node* node3 = createNodes3();
    LinkedList list3(node3);
    Node* cycleHead = list3.getHead();
    
    cout <<"List has a cycle: " << boolalpha << hasCycleBruteForce(cycleHead) << endl;
    cout <<"List has a cycle: " << boolalpha << hasCycle(cycleHead) << endl;

}








// Nth Node from the End
