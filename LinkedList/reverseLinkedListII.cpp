#include "../common.hpp"

/*
You are given the head of a singly linked list and two integers left and right where left <= right, 

reverse the nodes of the list from position left to position right (1-indexed), and return the reversed list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        // find left and right nodes
        ListNode* firstList   = nullptr;
        ListNode* leftNode    = nullptr;
        ListNode* rightNode   = nullptr;
        ListNode* curr  = head;

        int i = 1;
        // find leftNode
        while (i != left){
            if (i == left - 1) firstList = curr;
            curr = curr->next;
            i++;
        }
        leftNode = curr;

        // find rightNode
        while (i != right){
            curr = curr->next;
            i++;
        }
        rightNode = curr;

        ListNode* secondList = rightNode->next;
        rightNode->next = nullptr;


        curr = leftNode;

        // reverse subList from leftNode to rightNode
        ListNode* headOfReversedList = reverseList(leftNode);

        // reconnect the end of the reversed list to the secondList
        leftNode->next = secondList;

        if (firstList == nullptr) return headOfReversedList;
        else {
            firstList->next = headOfReversedList;
            return head;
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};

void print(ListNode* head){
    ListNode* curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(){
    Solution sol;

    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head  = new ListNode(1, node2);

    print(head);

    sol.reverseBetween(head, 2, 4);

    print(head);
}