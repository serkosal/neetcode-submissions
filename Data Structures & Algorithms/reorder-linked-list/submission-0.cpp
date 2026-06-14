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
    ListNode* insertAfter(ListNode* e1, ListNode* e)
    {
        if (!e1 && !e) return nullptr;

        ListNode* next = e1->next;
        e1->next = e;
        return e->next = next;
    }

    void reorderList(ListNode* head) 
    {
        stack<ListNode*> st;

        int k = 0;
        for (auto cur = head; cur; cur = cur->next)
        {
            ++k;
            st.push(cur);
        }

        auto cur = head;
        
        for (int i = 0; i < (k - 1) / 2; ++i)
        {
            cur = insertAfter(cur, st.top());
            st.pop();
            st.top()->next = nullptr;
        }
    }
};
