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
class Solution
{
public:
    ListNode *head1;

    bool solve(ListNode *head)
    {
        if (!head)
            return true;

        if (!solve(head->next))
            return false;

        if (head1->val != head->val)
            return false;
        head1 = head1->next;
        return true;
    }

    bool isPalindrome(ListNode *head)
    {
        head1 = head;
        return solve(head);
    }
};