class Solution {
public:
    bool repeatedSubstringPattern(const string &str) {
const size_t len=str.length();
size_t i=1,j=0;
int next[len];
memset(next,0,sizeof(next));
while(i<len){
if(str[i]==str[j]) next[i++]=++j;
else if(j==0) ++i;
else j=next[j-1];
}     
return (next[len-1]&&len%(len-next[len-1])==0); 
    }
};