struct compare{
bool operator()(ListNode* pnode1, ListNode* pnode2){
return pnode1->val>pnode2->val;}//重载比较符号，默认按照小于比，最大堆，这里想最小堆，因此重载大于符号
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
if(lists.empty()) return nullptr;
priority_queue<ListNode*,vector<ListNode*>,compare> pq{};
//for(size_t i=0;i<lists.size();++i) pq.push(lists[i]);//可能其中一个是空的
for(size_t i=0;i<lists.size();++i) if(lists[i]) pq.push(lists[i]);//error handling,不是!empty()，lists里面装的指针，直接判断头节点是否为空
ListNode* dummy=new ListNode(-1), *pcur=dummy;
while(!pq.empty()){
//pcur->next=new ListNode(pq.top()->val);//非front
pcur->next=pq.top();
pcur=pcur->next;
pq.pop();
if(pcur->next) pq.push(pcur->next);
}
pcur=dummy->next;
delete dummy;
return pcur;       
    }
};
