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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *dummy = new ListNode(-1);

        ListNode *k = dummy;
        ListNode *curr1 = head1;
        ListNode *curr2 = head2;

        while(curr1 && curr2){
          if(curr1->val < curr2->val){
            k->next = curr1;
            k = k->next;
            curr1=curr1->next;
          }else{
            k->next = curr2;
            k = k->next;
            curr2 = curr2->next;
          }
        }

        // if curr1 empty 
        if(!curr1 && curr2) k->next = curr2;
        if(!curr2 && curr1) k->next = curr1;

        return dummy->next;
    }
};
