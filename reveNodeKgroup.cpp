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
    ListNode* reverseKGroup(ListNode* head, int k) {
if(!head||k<=1) return head;
int count=0;
ListNode *dummy=new ListNode(-1), *pre=dummy, *cur=head, *after=nullptr;
dummy->next=head;
while(cur){
++count;
after=cur->next;//要保存起来next指针，受影响了，原来2->next是3，反过来之后就是1
if(count==k) pre=reverseMid(pre, cur->next), count=0;
cur=after;//要回到原来的next
}
return dummy->next;
}
private:
ListNode* reverseMid(ListNode* preStart, ListNode* passEnd){
ListNode* head=preStart->next, *cur=preStart->next->next;
while(cur!=passEnd){
ListNode* later=cur->next;
cur->next=preStart->next;
preStart->next=cur;
cur=later;
}        
head->next=cur;
return head;
    }
};