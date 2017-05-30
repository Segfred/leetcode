/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
if(!head) return nullptr;
RandomListNode* cur=head;
while(cur){
RandomListNode* psnd=new RandomListNode(cur->label);
psnd->next=cur->next;
cur->next=psnd;
cur=psnd->next;
}//end of copying next pointer

cur=head;
while(cur){
RandomListNode* psnd=cur->next;
psnd->random=cur->random? cur->random->next:nullptr;
cur=psnd->next;
}

RandomListNode* pnode=head->next;//保存头节点位置，要不然后面移动走就找不到了
cur=head;
while(cur){
RandomListNode* psnd=cur->next;
cur->next=psnd->next;
cur=psnd->next;//一步步来，先移动psnd的话psnd->next就找不到了，因此先移动前面的
psnd->next=cur? cur->next:nullptr;
}
return pnode;
    }
};



