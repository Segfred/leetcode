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
    ListNode* detectCycle(ListNode *head) {
        if(!head||!head->next) return nullptr;
        ListNode *pfast=head,*pslow=head;
        while(pfast->next&&pfast->next->next)
        {
            pslow=pslow->next;
            pfast=pfast->next->next;
            if (pfast==pslow) break;
        }
        if(!pfast->next||!pfast->next->next)
            return nullptr;
        pslow=head;
        while (pslow!=pfast) {
            pslow=pslow->next;
            pfast=pfast->next;
        }
        return pfast;
    }
};