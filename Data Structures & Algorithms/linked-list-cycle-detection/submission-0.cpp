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
    bool hasCycle(ListNode* head) 
    {
        ListNode* fast = head, *slow = head;

        while (slow->next && fast->next && fast->next->next)
        {
            if (slow->next == fast->next->next) return true;

            fast = fast->next->next;
            slow = slow->next;
        }   

        return false; 
    }
};
