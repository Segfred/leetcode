/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//比如1->2->3->4->5反转2，4之间之后变成1->4->3->2->5
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head||m>=n||m<1) return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        head=dummy;
        for(int i=1;i<=m-1;++i) head=head->next;
        ListNode *pre=head->next,*cur=head->next->next;
        for(int i=m;i<n;++i)
        {
            ListNode *later=cur->next;
            cur->next=pre;
            pre=cur;
            cur=later;
        }
        head->next->next=cur;//这里代表1->4->指向的是5（即4后面是5，当然这时候就没1什么事了）
        head->next=pre;//这里代表的是1->2，有1的事，先确定结尾再确定开头
        head=dummy->next;
        delete dummy;
        return head;
    }
    
};
