#include "../common.hpp"

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

    void print(ListNode* head){
        ListNode* curr = head;
        while(curr){
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

int main(){
    Solution sol;
    /*
   -1<-0<-1<-2<-3
                p
                   c
                   t
    */

    ListNode* node4 = new ListNode(3);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(1, node3);
    ListNode* node1 = new ListNode(0, node2);

    sol.print(node1);

    ListNode* prev = sol.reverseList(node1);

    sol.print(prev);
}