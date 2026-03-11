#include "../common.hpp"

/*
You are given an array of integers nums and the head of a linked list. 
Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.


nums = [1,2,3], head = []

-1 4 5
     c
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = dummy;

        unordered_set<int> removeSet(nums.begin(), nums.end());
        while(curr){
            if (removeSet.contains(curr->next->val)){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};