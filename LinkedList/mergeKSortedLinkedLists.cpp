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
    1. iterate over the given lists and merge two lists each time and append this merged list into a result list
    2. repeat this process again on the result list until we only have one list 
    3. return the resultant final list 
Time -> O(nlogk) ->Each merge round touches all N nodes, and there are log k merge rounds due to divide and conquer.
Space -> 0(logk) -> at each merge round we store worst case log k lists in our vector 
*/
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if (lists.empty()){
            return nullptr;
        }

        vector<ListNode*> merging = lists;
        while (merging.size() != 1){
            vector<ListNode*> mergedList;
            int n = merging.size();
            for (int i = 0; i < n; i+=2){
                ListNode* list1 = merging[i];
                ListNode* list2;
                if (i == n - 1){ // last list in odd number of lists 
                    list2 = nullptr;
                } else {
                    list2 = merging[i + 1];
                }
                ListNode* merged = mergeTwoLists(list1, list2);
                mergedList.push_back(merged);
            }
            merging = mergedList;
        }
        
        return merging[0];
    }
    /*
    [1,2,4],[1,3,5]

    -1->1->1->2->3->4->5

    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pointer1 = list1;
        ListNode* pointer2 = list2;
        
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        while(pointer1 && pointer2){
            if (pointer1->val < pointer2->val){
                curr->next = pointer1;
                pointer1   = pointer1->next;
                curr = curr->next;
            } else {
                curr->next = pointer2;
                pointer2   = pointer2->next;
                curr = curr->next;
            }
        }
        if (pointer1){
            curr->next = pointer1;
        }
        if (pointer2){
            curr->next = pointer2;
        }

        curr = head->next;
        delete head;
        return curr;
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
    // lists = [[1,2,4],[1,3,5],[3,6]]
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* list3 = new ListNode(3, new ListNode(6));

    vector<ListNode*> lists;

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode* mergedList = sol.mergeKLists(lists);

    sol.print(mergedList);

    // [[1,2,4], [1,3,5], [3,6], [7,8], [4, 6], [2, 3]]
    list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    list2 = new ListNode(1, new ListNode(3, new ListNode(5)));
    list3 = new ListNode(3, new ListNode(6));
    ListNode* list4 = new ListNode(7, new ListNode(8));
    ListNode* list5 = new ListNode(4, new ListNode(6));
    ListNode* list6 = new ListNode(2, new ListNode(3));

    vector<ListNode*> lists2;
    lists2.push_back(list1);
    lists2.push_back(list2);
    lists2.push_back(list3);
    lists2.push_back(list4);
    lists2.push_back(list5);
    lists2.push_back(list6);

    mergedList = sol.mergeKLists(lists2);
    sol.print(mergedList);
}