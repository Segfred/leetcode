class Solution {
public:
    int myAtoi(const string &str) {
if(str.empty()) return 0;
const int len=(int)str.length();
int sign=1, i=0, res=0;
while(i<len&&str[i]==' ') ++i;//i<len别忘了
if(str[i]=='+'||str[i]=='-') if(str[i++]=='-') sign=-1;
while(i<len&&str[i]>='0'&&str[i]<='9' ){
if(res>INT_MAX/10||res==INT_MAX/10&&str[i]>'7') return sign==-1? INT_MIN?INT_MAX;
res=10*res+str[i++]-'0';
}     
return res*sign;
    }
};