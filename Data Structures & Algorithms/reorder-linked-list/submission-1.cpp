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
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;

    while (head)
    {
        auto next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

void reorderList(ListNode* head) {
    auto m = head, l1 = head;
    for (auto f = m; f && f->next; m = m->next, f = f->next->next);

    auto l2 = reverseList(m->next);
    m->next = nullptr;
    
    while (l1 && l2) {
        auto t1 = l1->next, t2 = l2->next; 
        l1->next = l2;
        l1 = l2->next = t1;
        l2 = t2;
    }
}
};
