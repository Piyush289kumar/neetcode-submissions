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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *tm = head;
        while(tm){
            tm = tm->next;
            len++;
        }

        if(n == len){
            return head->next;
        }

        ListNode *curr = head;
        ListNode *prev = nullptr;
        int step = len - n;
        while(step--){
            prev = curr;
            curr = curr->next;            
        }

        prev->next = prev->next->next;

        return head;

    }
};
