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
    ListNode *startNode(ListNode *head, ListNode *slow){

        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return startNode(head, slow);      
        }
        return nullptr;
    }
};