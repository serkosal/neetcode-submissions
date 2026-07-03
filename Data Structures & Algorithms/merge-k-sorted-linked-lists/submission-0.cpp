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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return {};

        for (int sz = lists.size(); sz > 1; sz = lists.size()) {
            auto l1 = lists[sz - 1], l2 = lists[sz - 2];
            lists.resize(sz - 2);
            lists.push_back(mergeTwoLists(l1, l2));
        }
        
        return lists.back();
    }
};
