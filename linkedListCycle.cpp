#include "common.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    ListNode* node1 = new ListNode(1);
    ListNode* node4 = new ListNode(4, node1);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(12, node3);
    node1->next = node2;

    // 1->2->3->4->5
    //       s
    //             f  
    // 1->2
    // s
    //       f      

    cout << boolalpha << sol.hasCycle(node1) << endl;
}