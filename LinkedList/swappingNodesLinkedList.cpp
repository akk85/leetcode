#include "../common.hpp"

/*
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node 
from the beginning and the kth node from the end (the list is 1-indexed).

Thought process:
    Get all values into a stack and swap the kth values together
    we can introduce a dummy node at index zero of vec just to make indexing with k starighforward
    after wapping build the list from the vector and return the list ignoring the dummy node 
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
-1->1->2->3->4->5
               c
                 p
*/
class Solution {
public:
    // using a vector to store all node values and swap
    ListNode* swapNodes1(ListNode* head, int k) {
        vector<int> vec;
        vec.push_back(-1);

        ListNode* curr = head;

        while(curr){
            vec.push_back(curr->val);
            curr = curr->next;
        }

        int n = vec.size();
        int firstKth = vec[k];
        int lastKth  = vec[n - k];

        vec[k]      = lastKth;
        vec[n - k] = firstKth;


        head = new ListNode(vec[0]);

        int pointer = 1;
        curr = head;
        while(pointer < n){
            curr->next = new ListNode(vec[pointer]);
            curr = curr->next;
            pointer += 1;
        }

        return head->next;
    }

    // in place with two pointers no extra memory
    /*
    1 2 3 4 5
          c   s  

    using pointers, find first kth node and last kth node and swap theri values 
    */
    ListNode* swapNodes2(ListNode* head, int k) {
        ListNode* first = head;
        
        // kth from beginning
        int i = 1;
        while(i != k){
            first = first->next;
            i += 1;
        }

        // kth from end 
        ListNode* curr   = head;
        ListNode* second = first->next;

        while(second){
            curr   = curr->next;
            second = second->next;
        }

        swap(first->val, curr->val);

        return head;
    }
};
