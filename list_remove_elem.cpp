/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return nullptr;
        ListNode *pnode=nullptr;
        while(head&&head->val==val)
        {
            pnode=head;
            head=head->next;
            delete pnode;
        }
        pnode=head;
        while(pnode&&pnode->next)
        {
            if (pnode->next->val==val)
            {
                ListNode *ptemp=pnode->next;
                pnode->next=ptemp->next;
            }
            else
                pnode=pnode->next;
        }
        return head;
    }
};