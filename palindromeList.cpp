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
    bool isPalindrome(ListNode* head) {
if(!head||!head->next) return true;
front=head;   
bool result= true;
match(head,result);
return result;     
    }
private:
void match(ListNode* back, bool &res){
if(!back) return;//只要没到头一直往后走
match(back->next,res);//后退的时候自动调用上次的节点进行比较，从哪里调用就从哪里返回
//if(back) match(back->next,res);//，这样写back不存在了还会继续，是错的。
if(!res) return;//注意判断return 位置
if(front->val!=back->val) {res=false; return;}
front=front->next;
}
ListNode* front;
};