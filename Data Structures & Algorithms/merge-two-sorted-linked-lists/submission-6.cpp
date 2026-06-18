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
    ListNode* mergeTwoLists(const ListNode *l1, const ListNode *l2) {
        if (!l1 && !l2) return nullptr;
        ListNode *const head = new ListNode;

        for (ListNode * cur = head; ; ) {

            // s is the reference to the nonnullptr pointers l1 or l2 
            // with the smallest value
            auto& s = ( l1 && l2  
                ? (l1->val < l2->val ? l1 : l2)
                : (l1 ? l1 : l2)
            );

            cur->val = s->val; 
            s = s->next;
            
            if (!l1 && !l2) break;
            cur = cur->next = new ListNode;
        }

        return head;
    }
};
