class Solution {
public:
    ListNode* mergeTwoLists(const ListNode *l1, const ListNode *l2) {
        if (!l1 && !l2) return nullptr;
        ListNode *const head = new ListNode;

        for (ListNode* cur = head; ; cur = cur->next = new ListNode) {
            auto& smallest = ( l1 && l2 
                ? (l1->val < l2->val ? l1 : l2)
                : (l1 ? l1 : l2)
            );

            cur->val = smallest->val; 
            smallest = smallest->next;

            if (!l1 && !l2) return head;
        }

        return head;
    }
};
