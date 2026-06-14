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
    ListNode* reverseList(ListNode* head) 
    {
        if (!head) return nullptr;
        
        stack<int> st;
        ListNode* cur = head;
        while (cur)
        {
            st.push(cur->val);
            cur = cur->next;
        }

        ListNode* new_head = new ListNode(st.top());
        cur = new_head;
        st.pop();
        while (st.size())
        {
            cur->next = new ListNode(st.top());
            cur = cur->next;

            st.pop();
        }

        return new_head;
    }
};
