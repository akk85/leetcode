#include "../common.hpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
Thought process:    
    1. find middle point of the list using slow and fast pointers
    2. split the middle and reverse the second half portion
    3. using two pointers start connecting the various nodes from the two lists 
[0->1->2->3->    <-4<-5<-6]
                         f
          s.             p
                           c 
                           n
[0->1->2->3->    <-4<-5<-6]
 l                       r

*/
class Solution {
public:
    void reorderList(ListNode* head) {
        //1. middle slow points to middle Node;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        //2. reverse second portion
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

/*
[0->1->2->3->    <-4<-5<-6]
          f                    
                s

 0->6->1->5->2->4->3
*/      
        ListNode* first  = head;
        ListNode* second = prev;
        while (second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first  = temp1;
            second = temp2;
        }
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
    // [0, 1, 2, 3, 4, 5, 6]
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    sol.print(head);


    sol.reorderList(head);
    sol.print(head);

}