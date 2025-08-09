/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> ust;

        ListNode* curr = head;

        while(curr){
            if(ust.count(curr))
                return true;
            ust.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};