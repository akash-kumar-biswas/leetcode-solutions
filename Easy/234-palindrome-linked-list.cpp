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

    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* midNode = middleNode(head);

        ListNode* reverse_head = reverse(midNode);
    
        while(head != midNode){
            if(head->val != reverse_head->val)
                return false;
            head = head->next;
            reverse_head = reverse_head->next;
        }
        return true;
    }
};