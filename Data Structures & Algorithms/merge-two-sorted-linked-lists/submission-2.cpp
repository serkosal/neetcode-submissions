class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (!l1 && !l2) 
            return nullptr;

        ListNode* const new_head = new ListNode;
        ListNode* cur;

        for (cur = new_head; l1 && l2; cur = cur->next)
        {
            if (l1->val < l2->val)
            {
                cur->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                cur->val = l2->val;
                l2 = l2->next;
            }

            if (l1 || l2)
                cur->next = new ListNode;
        }

        if (!cur) return new_head;

        for (ListNode* l = (l1 ? l1 : l2); l; cur = cur->next)
        {
            cur->val = l->val;
            l = l->next;

            if (l)
                cur->next = new ListNode;
        }

        return new_head;    
    }
};
