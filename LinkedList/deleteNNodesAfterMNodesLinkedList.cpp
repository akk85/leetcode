#include "../common.hpp"

/*
You are given the head of a linked list and two integers m and n.

Traverse the linked list and remove some nodes in the following way:

Start with the head as the current node.
Keep the first m nodes starting with the current node.
Remove the next n nodes
Keep repeating steps 2 and 3 until you reach the end of the list.
Return the head of the modified list after removing the mentioned nodes.

m = 2, n = 3

-1 1 2 6 7 11 12 13
               c

   1,2,6,7,11,12]
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        while(curr){
            int mCount = m;
            int nCount = n;

            while(mCount != 0 && curr->next){
                curr = curr->next;
                mCount -= 1;
            }
            
            if (!curr->next) break;    

            while(nCount != 0 && curr->next){
                curr->next = curr->next->next;
                nCount -= 1;
            }
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};
