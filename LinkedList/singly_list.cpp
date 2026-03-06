#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {};
    Node(int x) : data(x), next(nullptr) {};
    Node(int x, Node* nextNode) : data(x), next(nextNode) {}; 
    
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {};
    LinkedList(Node* newHead) : head(newHead) {};

    ~LinkedList() = default;

    Node* getHead() const {
        return head;
    }
};
// a->b->c->d->e
int length(const Node* head) {
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
// h -> 1->2->3->4->5. 
void printNodes(const Node* head){
    if (!head){
        cout << "List is Empty" << endl;
        return;
    } 
    const Node* curr = head;
    while (curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// h -> 1->2->3->4->5.    
void insertAtHead(Node*& head, int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
// 1->2->3->4->5->v 
//              c
//
void insertAtTail(Node*& head, int value){
    Node* newNode = new Node(value);
    if (!head){
        head = newNode;
        return; 
    }

    Node* curr = head;
    while (curr->next){
        curr = curr->next;
    }
    curr->next = newNode;
}
// 0->1->2->7->3->4->5-
//       p
//          c
void insertAtPosition(Node*& head, int value, int index){
    if (index < 0){
        return;
    }

    // insert if at head
    Node* newNode = new Node(value);
    if (index == 0){
        newNode->next = head;
        head = newNode;
        return;
    }
    // some other position;
    int i {};
    Node* curr = head;
    while (curr && i < index - 1){
        curr = curr->next;
        i++;
    }
    if(!curr){
        delete newNode;
        return;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

bool contains(const Node* head, int value){
    const Node* curr = head;
    while(curr){
        if (curr->data == value){
            return true;
        }
        curr = curr->next;
    }
    return false;
}
// 1->2->3->4->5.   9
//             c
bool deleteByValue(Node*& head, int value){
    if (!head){
        return false;
    }
    if (head->data == value){
        Node*  temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* curr = head;
    while(curr->next && curr->next->data != value){
        curr = curr->next;
    }
    if (!curr->next){
        return false;
    }
    Node* temp = curr->next; // node to delete;
    curr->next = curr->next->next;
    delete temp;
    return true;
}
// 0->1->2->3->4->5  6
//                c             
bool deleteAtPosition(Node*& head, int index){
    if (!head){
        return false;
    }
    // delete head
    if (index == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    // delete at other position
    Node* curr = head;
    int i {};
    while(curr && i < index - 1){
        curr = curr->next;
        i++;
    }
    
    // check if node to delete exists
    if (!curr || !curr->next){
        return false;
    }

    // safe to delete node 
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return true;
}
// 0 1 2 3 4 5        8
//             c
Node* findNode(Node* head, int value){
    Node* curr = head;
    while (curr){
        if (curr->data == value){
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

//   0->1->2->3->4->5
//                  p  c.  t
// <-0<-1<-2<-3<-4<-5
Node* reverseIterative(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
// classic tortoise algorthm 
// 1->2->3->4->5->6
//          s
//                  f
// 0 1 2 3 4 5 
//       s
//             f
const Node* findMiddle(const Node* head){
    if (!head){
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

// 1->2->3->2->1
//             c
// vec = [1, 2, 3, 2, 1]
bool isPalindromeExtraSpace(const Node* head){
    vector<int> vec;
    if (!head){
        return true;
    }
    const Node* curr = head;
    while(curr){
        vec.push_back(curr->data);
        curr = curr->next;
    }
    int left {};
    int right = vec.size() - 1;
    while (left <= right){
        if (vec.at(left) != vec.at(right)){
            return false;
        }
        left ++;
        right --;
    }
    return true;
}
//         0 1 2 3 4 5   n = 5
//.        
//         s
//                   f

bool removeNthFromEnd(Node*& head, int n){
    if (!head || n <= 0){
        return false;
    }

    Node dummy(0);
    dummy.next = head;
    Node* slow = &dummy;
    Node* fast = &dummy;

    // move fast n steps
    for (int i = 0; i < n; i++){
        if (fast->next == nullptr){ // n too large
            return false;
        }
        fast = fast->next;
    }

    // move slow and fast until fast reached end
    while (fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    head = dummy.next;

    return true;

}

// 2 3 5 6 
//         n
// 2 4 6 8 10 
//     n
// 0 2 2 3 4 5 6 6 8 10
//.                  d 
Node* mergeSortedLists(Node* l1, Node* l2){
    Node dummy(0);
    Node* tail = &dummy;

    Node* node1 = l1;
    Node* node2 = l2;

    while (node1 && node2){
        if (node1->data <= node2->data){
            tail->next = node1;
            node1 = node1->next;
        } 
        else {
            tail->next = node2;
            node2 = node2->next;
        }
        tail = tail->next;
    }
    if (node1){
        tail->next = node1;
    }
    if (node2){
        tail->next = node2;
    }
    return dummy.next;
}
// 2  3 4 5 6 6 8 10
//   c
void removeDuplicatesSorted(Node* head){
    if (!head){
        return;
    }
    Node* curr = head;
    while(curr && curr->next){
        if (curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }

    }
}

// seen = [2 3 5 4]
// 2 3 5 4 7
//         c
void removeDuplicatesUnsorted(Node* head){
    if (!head){
        return;
    }
    unordered_set<int> seen;
    Node* curr = head;
    seen.insert(curr->data);

    while(curr->next){
        if (seen.count(curr->next->data)){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else {
            seen.insert(curr->next->data);
            curr = curr->next;
        }
    }

}

// 1 2 3 4 
// s  
// f
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
//   1 2 3 4 
//   s
//   f
//
Node* detectCycleStart(Node* head){
    if (!head || !head->next){
        return nullptr;
    }
    unordered_set<Node* > seen;
    Node* curr = head;

    while(curr){
        if (seen.count(curr)){
            return curr;
        }
        seen.insert(curr);
        curr = curr->next;
    }

    return nullptr;
}


int main(){
    Node* node5 = new Node(7);
    Node* node4 = new Node(5, node5);
    Node* node3 = new Node(3, node4);
    Node* node2 = new Node(2, node3);
    Node* node1 = new Node(1, node2);

    LinkedList list(node1);
    
    Node* head = list.getHead();

    
    Node* node10 = new Node(10);
    Node* node9  = new Node(8, node10);
    Node* node8  = new Node(6, node9);
    Node* node7  = new Node(4, node8);
    Node* node11 = new Node(2, node7);
    Node* node6  = new Node(2, node11);

    LinkedList list1(node6);
    
    Node* head1 = list1.getHead();
    cout << "Length of list is: " << length(head) << endl;
    printNodes(head);

    insertAtHead(head, 0);
    cout << "Length of new list is: " << length(head) << endl;
    printNodes(head);

    insertAtTail(head, 6);
    cout << "Length of new list is: " << length(head) << endl;
    printNodes(head);

    insertAtPosition(head, 7, 7);
    cout << "Length of new list is: " << length(head) << endl;
    printNodes(head);

    cout << "List contains node 8: " << boolalpha << contains(head, 7) << endl;

    cout<< "Deleted node by value: " << boolalpha << deleteByValue(head, 7) << endl;
    cout << "Length of new list is: " << length(head) << endl;
    printNodes(head);

    cout<< "Deleted node by position: " << boolalpha << deleteAtPosition(head, 6) << endl;
    cout << "Length of new list is: " << length(head) << endl;
    printNodes(head);

    Node* found = findNode(head, 1); 
    if (!found){
        cout << "Node not found!! " << endl;
    } else {
        cout << "Node found!! " << endl;
    }

    
    const Node* middleNode = findMiddle(head);

    cout << "Middle Node of list is node: " << middleNode->data << endl;

    cout << "Linked list is a palindrome: " << boolalpha << isPalindromeExtraSpace(head) << endl;
    printNodes(head);

    deleteAtPosition(head, 0);


    cout << "Before removeNthFromEnd" << endl;
    printNodes(head);

    cout << "removeNthFromEnd from the list: " << boolalpha << removeNthFromEnd(head, 5) << endl;

    cout << "Nodes after removeNthFromEnd" << endl;
    printNodes(head);

    //Before merging
    cout << endl;
    cout << "Before merging: " << endl;
    
    printNodes(head);
    printNodes(head1);
    Node* newHead = mergeSortedLists(head, head1);
    printNodes(newHead);

    cout << "After Sorting: " << endl;
    removeDuplicatesSorted(newHead);
    printNodes(newHead);

    // 2 3 2 5 4 3 5 7
    Node* node20  = new Node(5);
    Node* node19  = new Node(7, node20);
    Node* node18  = new Node(5, node19);   
    Node* node17  = new Node(3, node18);
    Node* node16  = new Node(4, node17);
    Node* node15  = new Node(5, node16);
    Node* node14  = new Node(2, node15);
    Node* node13  = new Node(3, node14);
    Node* node12  = new Node(2, node13);

    LinkedList list2(node12);

    Node* head2 = list2.getHead();

    cout << "Before Sorting: " << endl;
    printNodes(head2);
    cout << "After Sorting: " << endl;
    removeDuplicatesUnsorted(head2);
    printNodes(head2);


    // 1 2 3 4 
    Node* nodeA = new Node(1);
    Node* nodeD = new Node(4, nodeA);
    Node* nodeC = new Node(3, nodeD);
    Node* nodeB = new Node(2, nodeC);
    nodeA->next =  nodeB;

    LinkedList list3(nodeA);

    Node* head3 = list3.getHead();

    cout << "Has cycle: " << boolalpha << hasCycle(head3) << endl;

    Node* start = detectCycleStart(head3);
    if (start){
        cout << "Cycle starts at: " << start->data << endl;
    } else {
        cout << "No cycle detected: " << endl;
    }
}










