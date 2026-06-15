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
        ListNode* l = head, *r = head;

        for (; n && r; --n) r = r->next;
        if (n) return head;

        ListNode* prev = nullptr;
        while (r) {
            prev = l;
            l = l->next;
            r = r->next;
        }

        if (prev) prev->next = l->next;
        else head = l->next;
        delete l;

        return head;
    }
};
