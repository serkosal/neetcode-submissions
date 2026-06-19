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
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        ListNode* slow = head, 
            *fast = head->next ? head->next->next : head->next;

        if (slow == fast) return true;

        while (fast && slow) {
            if (slow == fast->next) return true;
            slow = slow->next;

            fast = fast->next;
            if (!fast) return false; 
            fast = fast->next;
        }

        return false;
    }
};
