//只需要遍历一次
class Solution {
public:
    int countPrimes(int n) {
if(n<=2) return 0;
vector<bool> flag(n,true);
int com=0, limit=sqrt(n);
for(int i=2;i<=limit;++i)
for(int j=i;i*j<n;++j) if(flag[i*j]) ++com, flag[i*j]=false;
return n-2-com;       
    }
};

class Solution {
public:
    int countPrimes(int n) {
if(n<3) return 0;
int end=sqrt(n), res=0;
bool isPrime[n];
memset(isPrime,true,sizeof(isPrime));
for(int i=2;i<=end;++i){
if(isPrime[i]){
for(int j=i*i;j<n;j+=i) isPrime[j]=false;}//end if
}// end for
for(int k=2;k<n;++k) if(isPrime[k]) ++res;
return res;
    }
};
