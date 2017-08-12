class Solution {
public:
    int myAtoi(string &str) {
int i=0, sign=1, res=0;
const int len=str.length();
while(i<len&&str[i]==' ') ++i;//needs handling
if(str[i]=='+'||str[i]=='-') if(str[i++]=='-') sign=-1;//别忘了前进i
while(i<len){
if(str[i]<'0'||str[i]>'9') break;
if(res>INT_MAX/10||res==INT_MAX/10&&str[i]>'7') return sign==1? INT_MAX:INT_MIN;//234567,7在最后一位，前面已经等于23456的时候相等
res=res*10+str[i++]-'0';//别忘了前进i
}

//if(res==INT_MAX&&sign==-1) return INT_MIN;//这样最小的数会当成溢出是错的
return  res*sign;
    }
};
