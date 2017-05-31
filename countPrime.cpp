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