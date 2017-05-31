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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
int carry=0;
ListNode* pcur=nullptr, *phead=nullptr;
stack<int> stc1{}, stc2{};
while(l1) stc1.push(l1->val), l1=l1->next;
while(l2) stc2.push(l2->val), l2=l2->next;
while(!stc1.empty()||!stc2.empty()||carry){
if(!stc1.empty()) carry+=stc1.top(), stc1.pop();
if(!stc2.empty()) carry+=stc2.top(), stc2.pop();
phead=new ListNode(carry%10);
carry/=10;
phead->next=pcur;
pcur=phead;
} 
return pcur;       
    }
};


