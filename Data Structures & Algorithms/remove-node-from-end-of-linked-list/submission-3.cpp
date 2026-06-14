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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        stack<ListNode*> st;
        for (auto cur = head; cur; cur = cur->next)
            st.push(cur);

        ListNode* cur, *prev = nullptr;
        for (int i = 0; i < n; ++i)
        {
            cur = st.top();
            st.pop();
        }
        if (st.size()) prev = st.top();

        if (!prev && !cur->next) return nullptr;
        else if (!prev && cur->next)
        {
            head = cur->next;
        }
        else
        {
            prev->next = cur->next;
            delete cur;
        }

        return head;
    }
};
