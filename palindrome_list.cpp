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
        head->next->next=cur;
        head->next=pre;
        head=dummy->next;
        delete dummy;
        return head;
    }
    
};


