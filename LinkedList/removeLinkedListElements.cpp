#include "../common.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
1,1,2,3,3]
1 2 3
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1); dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            if (curr->val == val){
                ListNode* toDelete = curr;
                prev->next = curr->next;
                curr       = curr->next;
                delete toDelete;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;

        return head;

    }
};
