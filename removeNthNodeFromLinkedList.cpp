#include "common.hpp"

// solution 1: using length  0(n) time and 0(1) space 

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEndTwoIterations(ListNode* head, int n) {
        ListNode* curr = head;
        int length {};
        while(curr){
            length ++;
            curr = curr->next;
        }

        if (length - n == 0){ // head
            return head->next;
        }

        curr = head;
        for (int i = 1; i < length - n; i++){ //get to node before nth node
            curr = curr->next;
        }

        ListNode* toRemove = curr->next;
        curr->next = curr->next->next;
        delete toRemove;
        return head;
    }

    void print(ListNode* head){
        ListNode* curr = head;
        while(curr){
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    /*
    Using a dummy node simplifies edge cases (like deleting the head)
    */
    ListNode* removeNthFromEndTwoPointers(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // move fast n steps 
        for (int i = 0; i < n; i++){
            fast = fast->next;
        }

        //move fast to end
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        //slow is at node before nth node;
        ListNode* toRemove = slow->next;
        slow->next = slow->next->next;
        delete toRemove;

        head = dummy->next;
        delete dummy;

        return head;
    }
};

int main(){
    Solution sol;

    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    // 1->2->3->4
    // s
    //       f

    // -1->1->2->3->4
    //  s
    //  f

    int n = 2;

    ListNode* removedNthNode = sol.removeNthFromEndTwoIterations(head, n);

    sol.print(removedNthNode);

    head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    removedNthNode = sol.removeNthFromEndTwoPointers(head, n);

    sol.print(removedNthNode);
    
}

