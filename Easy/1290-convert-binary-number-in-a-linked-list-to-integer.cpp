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
    int size_linkedlist(ListNode* head){
        ListNode* curr = head;
        int cnt = 0;

        while(curr != nullptr){
            curr = curr->next;
            cnt++;
        }
        return cnt;
    }

    int getDecimalValue(ListNode* head) {
       int i = size_linkedlist(head) - 1; 

       ListNode* curr = head;
       int num = 0;

        while(curr != nullptr){
            num |= (curr->val) * (1<<i);
            curr = curr->next;
            i--;
        }
        return num;
    }
};