#include "../common.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> seen;

        ListNode* curr = headA;

        while(curr){
            seen.insert(curr);
            curr = curr->next;
        }

        curr = headB;

        while(curr){
            if (seen.contains(curr)){
                return curr;
            }
            curr = curr->next;
        }

        return nullptr;
    }
};