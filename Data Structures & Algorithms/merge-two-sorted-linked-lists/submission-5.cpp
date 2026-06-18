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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = l1 || l2 ? new ListNode : nullptr;
        auto* cur = res;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->val = l1->val;
                l1 = l1->next;
            }
            else {
                cur->val = l2->val;
                l2 = l2->next;
            }

            if (l1 || l2) cur = cur->next = new ListNode;
        }
        
        l1 = l1 ? l1 : l2;
        if (!l1) return res;
        while (true) {
            cur->val = l1->val;
            l1 = l1->next;
            if (!l1) break;
            cur = cur->next = new ListNode();
        }

        return res;
    }
};
