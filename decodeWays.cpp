#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
int numDecodings(string s) {
    if (s.empty()||s[0]=='0') return 0;
    int w2 (1);
    int w1 (1);
    int w=w1;//w=w1+w2 but w2 is unvisible now,so w＝0，w+=w1
    for (size_t i=2; i<=s.size(); i++) {//begin from the third number 
        w = (s[i-1] == '0') ? 0 : w1;
        if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6'))
            w += w2;
        w2 = w1;
        w1 = w;
    }
    return w;
}
};

class Solution {
public:
    int numDecodings(string str) {
if(str.empty()||str[0]=='0') return 0;
int cur=1,pre1=1,pre2=1;//注意pre2不能初始化为0，否则全是0,pre=1，默认第一位合法，所以cur也可以默认合法
for(size_t i=2;i<=str.size();++i){
cur=str[i-1]=='0'? 0:pre1;
if(str[i-2]=='1'||str[i-2]=='2'&&str[i-1]>='0'&&str[i-1]<='6') cur+=pre2;
pre2=pre1, pre1=cur;//别忘了滚动
}  
return cur;     
    }
};
