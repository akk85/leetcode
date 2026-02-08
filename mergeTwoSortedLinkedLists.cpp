#include "common.hpp"


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
1->2->4
        p1
1->3->5
     p2

1->1->2->3->4->5
n             
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pointer1 = list1;
        ListNode* pointer2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;

        while (pointer1 && pointer2){
            if (pointer1->val < pointer2->val){
                node->next = pointer1;
                pointer1 = pointer1->next;
                node = node->next;
            } else {
                node->next = pointer2;
                pointer2 = pointer2->next;
                node = node->next;
            }
        }

        if (pointer1){
            node->next = pointer1;
        }
        if (pointer2){
            node->next = pointer2;
        }

        node = dummy->next;
        delete dummy;

        return node;

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
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(5)));

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    sol.print(mergedList);
}