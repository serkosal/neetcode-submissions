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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if (!list1 && !list2) 
            return nullptr;

        ListNode* const new_head = new ListNode;
        ListNode* cur = new_head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                cur->val = list2->val;
                list2 = list2->next;
            }

            if (list1 || list2)
                cur->next = new ListNode;

            cur = cur->next;
        }

        if (!cur) return new_head;
        
        ListNode* list;
        if (list1) list = list1;
        else list = list2;

        while (list)
        {
            cur->val = list->val;
            list = list->next;

            if (list)
                cur->next = new ListNode;

            cur = cur->next;
        }


        return new_head;    
    }
};
