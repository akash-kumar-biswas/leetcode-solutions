/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> ust;

        ListNode *curr = head;

        while (curr)
        {
            if (ust.count(curr))
                return curr;
            ust.insert(curr);
            curr = curr->next;
        }
        return nullptr;
    }
};