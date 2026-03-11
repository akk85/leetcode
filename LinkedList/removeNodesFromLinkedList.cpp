#include "../common.hpp"

/*
You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

Thought process:
    we need to iterate list in reverse order
    we can reverse the linked list
    iterate the list and keep track of greatest value we have seen
    if node is smaller than this we remove it
    after traversal reverse the list again to return it to original state

    <-5<-2<-13<-3<-8
                   p
                     c
                    t 





*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        prev->next = head;

        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* head = reverseList(head);
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = dummy;

        int greatest = dummy->val;
        while(curr){
            if (curr->next->val < greatest){
                curr->next = curr->next->next;
            } 
            else {
                curr = curr->next;
                greatest = max(greatest, curr->val);
            }
        }

        head = dummy->next;
        delete dummy;

        ListNode* head = reverseList(head);

        return head;
    }
};
