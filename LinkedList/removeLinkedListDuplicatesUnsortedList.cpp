#include "../common.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
2,1,4,1,2,3
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        unordered_set<int> seen;
        while(curr){
            if (seen.contains(curr->val)){
                ListNode* duplicateNode = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete duplicateNode;
            }
            else {
                seen.insert(curr->val);
                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;

        delete dummy;

        return head;
    }
};
