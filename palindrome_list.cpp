//
//  main.cpp
//  leet_huiwen
//
//  Created by Asmita on 2017/03/11.
//  Copyright © 2017年 Asmita. All rights reserved.
//one-pass O(n) time complexity and o(1) space complexity

#include <iostream>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
if(!head||!head->next) return true;
ListNode* pslow=head, *pfast=head;
while(pfast->next&&pfast->next->next) pslow=pslow->next, pfast=pfast->next->next;//不是pfast而是pfast->next开始
ListNode* head2=pslow->next, *pre=nullptr;//第二段head直接接地，注意此细节处理
while(head2){
ListNode* after=head2->next;
head2->next=pre;
pre=head2;
head2=after;
}  //reverse the second half list
while(pre){
if(pre->val!=head->val) return false;
head=head->next, pre=pre->next;
}
return true;
    }
};


