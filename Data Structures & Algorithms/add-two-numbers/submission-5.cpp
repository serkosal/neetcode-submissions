class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1 || l2 ? new ListNode : nullptr;
        for (auto* cur = res; cur; cur = cur->next) {
            const int 
                sum = cur->val + (l1 ? l1->val : 0) + (l2 ? l2->val : 0), 
                remainder = sum / 10;
            cur->val = sum % 10;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            
            if (remainder || l1 || l2) 
                cur->next = new ListNode(remainder);
        }
        return res;
    }
};
