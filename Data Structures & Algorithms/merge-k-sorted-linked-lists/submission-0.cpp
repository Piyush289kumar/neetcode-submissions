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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(auto list : lists){
            if(list){
                int val = list->val;
                ListNode *node = list;

                pq.push({val, node});
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while(!pq.empty()){
            pair<int, ListNode*> record = pq.top();
            pq.pop();

            ListNode *newNode = new ListNode(record.first);
            tail->next = newNode;
            tail = tail->next;

            if(record.second->next){
                int next_node_val = record.second->next->val;
                ListNode *next_node = record.second->next;

                pq.push({next_node_val, next_node});
            }
        }

        return dummy->next;
    }
};
















